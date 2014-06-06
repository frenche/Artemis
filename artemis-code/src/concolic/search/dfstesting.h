/*
 * Copyright 2012 Aarhus University
 *
 * Licensed under the GNU General Public License, Version 3 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *          http://www.gnu.org/licenses/gpl-3.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DFSTESTING_H
#define DFSTESTING_H

#include "randomaccesssearch.h"

namespace artemis
{

/**
 *  This is an example implementation of RandomAccessSearch which re-implements depth-first search.
 *  Used for testing.
 */

class DfsTesting : public RandomAccessSearch
{
public:
    DfsTesting(TraceNodePtr tree, uint searchBudget, uint depthLimit);

protected:
    QPair<bool, ExplorationDescriptor> nextTarget(QList<ExplorationDescriptor> possibleTargets);

private:
    unsigned int mDepthLimit;
};

} // namespace artemis
#endif // DFSTESTING_H