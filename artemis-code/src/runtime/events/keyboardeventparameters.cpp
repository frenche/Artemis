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
#include "keyboardeventparameters.h"
#include "artemisglobals.h"
#include "util/randomutil.h"

namespace artemis
{

KeyboardEventParameters::KeyboardEventParameters(QObject* parent, QString eventType, bool canBubble, bool cancelable,
        QString keyIdentifier,  unsigned int keyLocation,
        bool ctrlKey, bool altKey, bool shiftKey, bool metaKey, bool altGraphKey)
    : EventParameters(parent)
{
    Q_ASSERT(!eventType.isEmpty());
    this->eventType = eventType;
    this->canBubble = canBubble;
    this->cancelable = cancelable;
    this->keyIdentifier = keyIdentifier;
    this->keyLocation = keyLocation;
    this->ctrlKey = ctrlKey;
    this->altKey = altKey;
    this->shiftKey = shiftKey;
    this->metaKey = metaKey;
    this->altGraphKey = altGraphKey;
}

QString KeyboardEventParameters::js_string()
{
    if (!memo_js.isEmpty())
        { return memo_js; }

    QString rand_id = generate_random_js_id();
    QString res = "var " + rand_id + " = document.createEvent(\"KeyboardEvent\");";
    res = res + " " + rand_id + ".initKeyboardEvent(";
    res += eventType + ",";
    res += bool_tostring(canBubble) + ",";
    res += bool_tostring(cancelable) + ",";
    res += "null,";
    res += quote_string(keyIdentifier) + ",";
    res += keyLocation + ",";
    res += bool_tostring(ctrlKey) + ",";
    res += bool_tostring(altKey) + ",";
    res += bool_tostring(shiftKey) + ",";
    res += bool_tostring(metaKey) + ",";
    res += bool_tostring(altGraphKey) + ");";

    res += "this.dispatchEvent(" + rand_id + ");";

    memo_js = res;
    return res;
}

EventType KeyboardEventParameters::type() const
{
    return KEY_EVENT;
}

}
