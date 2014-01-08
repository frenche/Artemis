
OBJECTS_DIR = build
MOC_DIR = build
DESTDIR = dist

QMAKE_CXXFLAGS += -g \
    -DEXE_BUILD_DATE="`date +'\"%d-%m-%Y_%H:%M:%S\"'`" \
    -Wno-unused-parameter

DEFINES += ARTEMIS=1

HEADERS += src/runtime/input/ajaxinput.h \
    src/strategies/prioritizer/constantprioritizer.h \
    src/strategies/prioritizer/prioritizerstrategy.h \
    src/strategies/prioritizer/randomprioritizer.h \
    src/strategies/inputgenerator/targets/targetgenerator.h \
    src/runtime/options.h \
    src/runtime/browser/ajax/ajaxrequest.h \
    src/runtime/browser/ajax/ajaxrequestlistener.h \
    src/runtime/browser/cookies/immutablecookiejar.h \
    src/runtime/input/events/baseeventparameters.h \
    src/runtime/input/events/domelementdescriptor.h \
    src/runtime/input/events/eventhandlerdescriptor.h \
    src/runtime/input/events/eventparameters.h \
    src/runtime/input/events/eventypes.h \
    src/runtime/input/events/keyboardeventparameters.h \
    src/runtime/input/events/mouseeventparameters.h \
    src/runtime/executableconfiguration.h \
    src/runtime/input/baseinput.h \
    src/runtime/input/dominput.h \
    src/runtime/input/inputsequence.h \
    src/runtime/input/timerinput.h \
    src/runtime/browser/executionresult.h \
    src/runtime/browser/webkitexecutor.h \
    src/runtime/browser/timer.h \
    src/runtime/worklist/deterministicworklist.h \
    src/runtime/worklist/worklist.h \
    src/strategies/termination/numberofiterationstermination.h \
    src/strategies/termination/terminationstrategy.h \
    src/strategies/inputgenerator/inputgeneratorstrategy.h \
    src/strategies/inputgenerator/randominputgenerator.h \
    src/strategies/inputgenerator/targets/jquerylistener.h \
    src/strategies/inputgenerator/targets/jquerytarget.h \
    src/strategies/inputgenerator/targets/legacytarget.h \
    src/strategies/inputgenerator/targets/targetdescriptor.h \
    src/runtime/runtime.h \
    src/artemisglobals.h \
    src/util/randomutil.h \
    src/model/coverage/coveragelistener.h \
    src/model/coverage/sourceinfo.h \
    src/model/coverage/coveragetooutputstream.h \
    src/model/coverage/codeblockinfo.h \
    src/util/loggingutil.h \
    src/util/fileutil.h \
    src/util/urlutil.h \
    src/statistics/statsstorage.h \
    src/statistics/writers/pretty.h \
    src/exceptionhandlingqapp.h \
    src/runtime/browser/executionresultbuilder.h \
    src/strategies/inputgenerator/form/forminputgenerator.h \
    src/strategies/inputgenerator/form/staticforminputgenerator.h \
    src/strategies/inputgenerator/event/eventparametergenerator.h \
    src/strategies/inputgenerator/event/staticeventparametergenerator.h \
    src/strategies/inputgenerator/form/constantstringforminputgenerator.h \
    src/strategies/prioritizer/coverageprioritizer.h \
    src/runtime/appmodel.h \
    src/model/javascriptstatistics.h \
    src/strategies/prioritizer/readwriteprioritizer.h \
    src/strategies/prioritizer/collectedprioritizer.h \
    src/runtime/input/events/toucheventparameters.h \
    src/model/pathtracer.h \
    src/runtime/toplevel/artemisruntime.h \
    src/runtime/browser/artemiswebview.h \
    src/runtime/browser/artemiswebpage.h \
    src/concolic/search/search.h \
    src/concolic/solver/solver.h \
    src/concolic/search/searchdfs.h \
    src/concolic/executiontree/nodes/trace.h \
    src/concolic/entrypoints.h \
    src/concolic/executiontree/tracebuilder.h \
    src/runtime/toplevel/concolicruntime.h \
    src/concolic/traceclassifier.h \
    src/runtime/demomode/demowindow.h \
    src/concolic/executiontree/traceprinter.h \
    src/concolic/executiontree/tracevisitor.h \
    src/runtime/demomode/initialanalysiswidget.h \
    src/runtime/demomode/artemisbrowserwidget.h \
    src/runtime/toplevel/manualruntime.h \
    src/runtime/input/events/unknowneventparameters.h \
    src/concolic/traceeventdetectors.h \
    src/concolic/tracestatistics.h \
    src/concolic/solver/solution.h \
    src/concolic/solver/expressionprinter.h \
    src/runtime/demomode/traceviewerdialog.h \
    src/concolic/pathcondition.h \
    src/concolic/executiontree/nodes/traceunexplored.h \
    src/concolic/executiontree/nodes/tracebranch.h \
    src/concolic/executiontree/nodes/traceconcretebranch.h \
    src/concolic/executiontree/nodes/tracesymbolicbranch.h \
    src/concolic/executiontree/tracenodes.h \
    src/concolic/executiontree/tracemerger.h \
    src/concolic/executiontree/tracedisplay.h \
    src/runtime/demomode/imageviewer/imageviewerwidget.h \
    src/runtime/demomode/imageviewer/imageviewerdialog.h \
    src/concolic/solver/expressionvalueprinter.h \
    src/concolic/solver/expressionfreevariablelister.h \
    src/concolic/solver/constraintwriter/abstract.h \
    src/concolic/solver/constraintwriter/kaluza.h \
    src/concolic/solver/constraintwriter/z3str.h \
    src/concolic/solver/z3solver.h \
    src/concolic/solver/kaluzasolver.h \
    src/runtime/toplevel/artformruntime.h \
    src/runtime/input/forms/formfielddescriptor.h \
    src/runtime/input/forms/forminputcollection.h \
    src/concolic/executiontree/nodes/traceunexploredunsat.h \
    src/concolic/executiontree/nodes/traceunexploredmissed.h \
    src/concolic/executiontree/nodes/traceunexploredunsolvable.h \
    src/concolic/mockentrypointdetector.h \
    src/runtime/input/clickinput.h \
    src/concolic/executiontree/tracedisplayoverview.h \
    src/concolic/solver/cvc4solver.h \
    src/concolic/solver/constraintwriter/cvc4.h \
    src/concolic/solver/constraintwriter/smt.h

SOURCES += src/runtime/input/ajaxinput.cpp \
    src/strategies/prioritizer/constantprioritizer.cpp \
    src/strategies/prioritizer/randomprioritizer.cpp \
    src/strategies/inputgenerator/targets/targetgenerator.cpp \
    src/runtime/browser/ajax/ajaxrequest.cpp \
    src/runtime/browser/ajax/ajaxrequestlistener.cpp \
    src/runtime/browser/cookies/immutablecookiejar.cpp \
    src/runtime/input/events/baseeventparameters.cpp \
    src/runtime/input/events/domelementdescriptor.cpp \
    src/runtime/input/events/eventhandlerdescriptor.cpp \
    src/runtime/input/events/eventtypes.cpp \
    src/runtime/input/events/keyboardeventparameters.cpp \
    src/runtime/input/events/mouseeventparameters.cpp \
    src/runtime/browser/artemiswebview.cpp \
    src/runtime/browser/artemiswebpage.cpp \
    src/runtime/executableconfiguration.cpp \
    src/runtime/input/dominput.cpp \
    src/runtime/input/inputsequence.cpp \
    src/runtime/input/timerinput.cpp \
    src/runtime/browser/executionresult.cpp \
    src/runtime/browser/webkitexecutor.cpp \
    src/runtime/browser/timer.cpp \
    src/runtime/worklist/deterministicworklist.cpp \
    src/strategies/termination/numberofiterationstermination.cpp \
    src/strategies/inputgenerator/randominputgenerator.cpp \
    src/strategies/inputgenerator/targets/jquerylistener.cpp \
    src/strategies/inputgenerator/targets/jquerytarget.cpp \
    src/strategies/inputgenerator/targets/legacytarget.cpp \
    src/strategies/inputgenerator/targets/targetdescriptor.cpp \
    src/runtime/runtime.cpp \
    src/util/loggingutil.cpp \
    src/util/randomutil.cpp \
    src/model/coverage/coveragelistener.cpp \
    src/model/coverage/sourceinfo.cpp \
    src/model/coverage/coveragetooutputstream.cpp \
    src/model/coverage/codeblockinfo.cpp \
    src/util/fileutil.cpp \
    src/util/urlutil.cpp \
    src/statistics/statsstorage.cpp \
    src/statistics/writers/pretty.cpp \
    src/exceptionhandlingqapp.cpp \
    src/runtime/browser/executionresultbuilder.cpp \
    src/strategies/inputgenerator/event/staticeventparametergenerator.cpp \
    src/strategies/inputgenerator/form/staticforminputgenerator.cpp \
    src/strategies/inputgenerator/form/constantstringforminputgenerator.cpp \
    src/strategies/prioritizer/coverageprioritizer.cpp \
    src/runtime/appmodel.cpp \
    src/model/javascriptstatistics.cpp \
    src/strategies/prioritizer/readwriteprioritizer.cpp \
    src/strategies/prioritizer/collectedprioritizer.cpp \
    src/runtime/input/events/toucheventparameters.cpp \
    src/model/pathtracer.cpp \
    src/runtime/toplevel/artemisruntime.cpp \
    src/concolic/solver/expressionprinter.cpp \
    src/concolic/solver/solver.cpp \
    src/concolic/entrypoints.cpp \
    src/runtime/toplevel/concolicruntime.cpp \
    src/concolic/executiontree/tracebuilder.cpp \
    src/concolic/traceclassifier.cpp \
    src/runtime/demomode/demowindow.cpp \
    src/concolic/executiontree/traceprinter.cpp \
    src/concolic/executiontree/tracevisitor.cpp \
    src/runtime/demomode/initialanalysiswidget.cpp \
    src/runtime/demomode/artemisbrowserwidget.cpp \
    src/runtime/toplevel/manualruntime.cpp \
    src/runtime/input/events/unknowneventparameters.cpp \
    src/concolic/traceeventdetectors.cpp \
    src/concolic/tracestatistics.cpp \
    src/concolic/solver/solution.cpp \
    src/runtime/demomode/traceviewerdialog.cpp \
    src/strategies/inputgenerator/form/forminputgenerator.cpp \
    src/concolic/pathcondition.cpp \
    src/concolic/executiontree/nodes/traceunexplored.cpp \
    src/concolic/executiontree/nodes/tracebranch.cpp \
    src/concolic/executiontree/nodes/traceconcretebranch.cpp \
    src/concolic/executiontree/nodes/tracesymbolicbranch.cpp \
    src/concolic/executiontree/tracemerger.cpp \
    src/concolic/executiontree/tracedisplay.cpp \
    src/runtime/demomode/imageviewer/imageviewerwidget.cpp \
    src/runtime/demomode/imageviewer/imageviewerdialog.cpp \
    src/concolic/search/searchdfs.cpp \
    src/concolic/solver/expressionvalueprinter.cpp \
    src/concolic/solver/expressionfreevariablelister.cpp \
    src/concolic/solver/constraintwriter/abstract.cpp \
    src/concolic/solver/constraintwriter/kaluza.cpp \
    src/concolic/solver/constraintwriter/z3str.cpp \
    src/concolic/solver/z3solver.cpp \
    src/concolic/solver/kaluzasolver.cpp \
    src/runtime/toplevel/artformruntime.cpp \
    src/runtime/input/forms/formfielddescriptor.cpp \
    src/runtime/input/forms/forminputcollection.cpp \
    src/concolic/executiontree/nodes/traceunexploredunsat.cpp \
    src/concolic/executiontree/nodes/traceunexploredmissed.cpp \
    src/concolic/executiontree/nodes/traceunexploredunsolvable.cpp \
    src/concolic/mockentrypointdetector.cpp \
    src/runtime/input/clickinput.cpp \
    src/concolic/executiontree/tracedisplayoverview.cpp \
    src/concolic/solver/cvc4solver.cpp \
    src/concolic/solver/constraintwriter/cvc4.cpp \
    src/concolic/solver/constraintwriter/smt.cpp

QT += network
