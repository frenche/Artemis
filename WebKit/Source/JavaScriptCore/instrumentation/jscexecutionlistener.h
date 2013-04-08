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

#ifdef ARTEMIS
#ifndef JSCEXECUTIONLISTENER_H
#define JSCEXECUTIONLISTENER_H

#include "bytecodeinfo.h"

namespace JSC {
    class CodeBlock;
    class Instruction;
    class ExecState;
    class Interpreter;
}


namespace jscinst {

class JSCExecutionListener
{

public:
    JSCExecutionListener();
    virtual void javascript_eval_call(const char * eval_string); //__attribute__((noreturn));
    virtual void javascript_bytecode_executed(JSC::Interpreter* interpreter, JSC::CodeBlock*, JSC::Instruction* inst, const JSC::BytecodeInfo&); //__attribute__((noreturn));
    virtual void javascriptConstantStringEncountered(std::string constant); //__attribute__((noreturn));
    virtual void javascript_property_read(std::string propertyName, JSC::ExecState*); //__attribute__((noreturn));
    virtual void javascript_property_written(std::string propertyName, JSC::ExecState*); //__attribute__((noreturn));

    /* Constant String Instrumentation */
public:
    inline bool isConstantStringInstrumentationEnabled()
    {
        return m_constantStringInstrumentationEnabled;
    }

    inline void enableConstantStringInstrumentation()
    {
        m_constantStringInstrumentationEnabled = true;
    }

private:
    bool m_constantStringInstrumentationEnabled;


};

extern JSCExecutionListener* jsc_listener;

void register_jsc_listener(JSCExecutionListener* listener);
JSCExecutionListener* get_jsc_listener();

}

#endif // JSCEXECUTIONLISTENER_H
#endif
