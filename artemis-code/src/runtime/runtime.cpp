/*
 Copyright 2011 Simon Holm Jensen. All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are
 permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this list of
 conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice, this list
 of conditions and the following disclaimer in the documentation and/or other materials
 provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY SIMON HOLM JENSEN ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those of the
 authors and should not be interpreted as representing official policies, either expressed
 or implied, of Simon Holm Jensen
 */

#include <iostream>

#include "worklist/deterministicworklist.h"
#include "statistics/statsstorage.h"
#include "statistics/writers/pretty.h"
#include "coverage/coveragetooutputstream.h"
#include "strategies/inputgenerator/randominputgenerator.h"
#include "strategies/termination/numberofiterationstermination.h"
#include "strategies/prioritizer/constantprioritizer.h"

#include "runtime.h"

using namespace std;

namespace artemis
{

/**
 * This is the main-loop used by artemis.
 *
 * startAnalysis -> preConcreteExecution -> postConcreteExecution -> finishAnalysis
 *                              ^------------------|
 */
Runtime::Runtime(QObject* parent, const Options& options, QUrl url) : QObject(parent)
{

    /** Proxy support **/

    if (!options.useProxy.isNull()) {
        QStringList parts = options.useProxy.split(QString(":"));
        QNetworkProxy proxy(QNetworkProxy::HttpProxy, parts.at(0), parts.at(1).toShort());
        QNetworkProxy::setApplicationProxy(proxy);
    }

    /** Ajax support and cookie injection **/

    AjaxRequestListener* ajaxRequestListner = new AjaxRequestListener(this);

    ImmutableCookieJar *immutable_cookie_jar = new ImmutableCookieJar(
            options.presetCookies, url.host());
    ajaxRequestListner->setCookieJar(immutable_cookie_jar);

    /** JQuery support **/

    JQueryListener* jqueryListener = new JQueryListener(this);

    /** Runtime Objects **/

    mWebkitExecutor = new WebKitExecutor(this, options.presetFormfields, jqueryListener, ajaxRequestListner);

    mInputgenerator = new RandomInputGenerator(this, new TargetGenerator(this, jqueryListener), options.numberSameLength);
    mTerminationStrategy = new NumberOfIterationsTermination(this, options.iterationLimit);
    mPrioritizerStrategy = new ConstantPrioritizer(this);

    mWorklist = new DeterministicWorkList(this);

    QObject::connect(mWebkitExecutor,
            SIGNAL(sigExecutedSequence(ExecutableConfiguration*, ExecutionResult*)), this,
            SLOT(postConcreteExecution(ExecutableConfiguration*, ExecutionResult*)));

}

/**
 * @brief Start the analysis for url
 * @param url
 */
void Runtime::startAnalysis(QUrl url)
{
    // TODO possible memory leak
    ExecutableConfiguration* initialConfiguration =
    		new ExecutableConfiguration(NULL, new InputSequence(NULL), url);

    mWorklist->add(initialConfiguration, 0);

    preConcreteExecution();
}

/**
 * @brief Pre-concrete-execution
 */
void Runtime::preConcreteExecution()
{
	if (mWorklist->empty() ||
		mTerminationStrategy->should_terminate()) {

        finishAnalysis();
		return;
	}

	// TODO remove this memory leak
	ExecutableConfiguration* nextConfiguration = mWorklist->remove();

    mWebkitExecutor->executeSequence(nextConfiguration); // calls the slExecutedSequence method as callback
}

/**
 * @brief Post-concrete-execution
 * @param configuration
 * @param result
 */
void Runtime::postConcreteExecution(ExecutableConfiguration* configuration, ExecutionResult* result)
{
    mPrioritizerStrategy->reprioritize(mWorklist);

	QList<ExecutableConfiguration*> newConfigurations = mInputgenerator->add_new_configurations(configuration, result);

	foreach (ExecutableConfiguration* newConfiguration, newConfigurations) {
		mWorklist->add(newConfiguration, mPrioritizerStrategy->prioritize(newConfiguration, result));
	}

	statistics()->accumulate("InputGenerator::added-configurations", newConfigurations.size());

    preConcreteExecution();
}

void Runtime::finishAnalysis() {

    mWebkitExecutor->finish_up();

	cout << "Artemis: Testing done..." << endl;

	cout << "\n\n === Coverage information for execution === \n";
	write_coverage_report(cout, coverage());

	cout << "\n=== Statistics ===\n";
	StatsPrettyWriter::write(cout, statistics());
	cout << "\n=== Statistics END ===\n";
	cout << endl;

	qDebug() << "Artemis terminated on: " << QDateTime::currentDateTime().toString() << endl;
	qDebug() << "Build timestamp: " << EXE_BUILD_DATE << endl;

    //delete executor;
    //delete wl;
    //delete termination;

    emit sigTestingDone();
}

CodeCoverage Runtime::coverage() {
    return mWebkitExecutor->coverage();
}

} /* namespace artemis */