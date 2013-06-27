/*
 * Copyright 2012 Aarhus University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 // AUTO GENERATED - DO NOT MODIFY

#ifndef SYMBOLIC_SYMBOLICBOOLEAN_H
#define SYMBOLIC_SYMBOLICBOOLEAN_H

#include <string>

#include "JavaScriptCore/wtf/ExportMacros.h"
#include "JavaScriptCore/runtime/UString.h"

#include "visitor.h"
#include "booleanexpression.h"

#ifdef ARTEMIS

namespace Symbolic
{

class SymbolicBoolean : public BooleanExpression
{
public:
    explicit SymbolicBoolean(std::string identifier);
    void accept(Visitor* visitor);

	inline std::string getIdentifier() {
		return m_identifier;
	}

private:
	std::string m_identifier;

};
}

#endif
#endif // SYMBOLIC_SYMBOLICBOOLEAN_H