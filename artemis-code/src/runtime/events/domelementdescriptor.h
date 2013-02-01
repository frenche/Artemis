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
#ifndef DOMELEMENTDESCRIPTOR_H
#define DOMELEMENTDESCRIPTOR_H

#include <QObject>
#include <QtWebKit>
#include <QDebug>

// TODO convert to new memory model

namespace artemis {

class DOMElementDescriptor : public QObject
{
    Q_OBJECT

    public:
        DOMElementDescriptor(QObject* parent, QWebElement* elm);
        DOMElementDescriptor(QObject* parent, const DOMElementDescriptor* other);

        QWebElement get_element(QWebPage* page) const;
        QString get_tag_name();
        QString get_id();
        QString get_class();
        bool is_invalid() const;

        QDebug friend operator<<(QDebug dbg, const DOMElementDescriptor &e);

    private:
        QString id;
        QString tag_name;
        QString frame_name;
        QString class_line;

        /*
         Path from the main_frame to the frame containig the element
         */
        QList<int> frame_path;
        /*
         Path from the frame containing the element to the actual element
         */
        QList<int> element_path;

        void set_frame_path(QWebElement* elm);
        void set_element_path(QWebElement* elm);

        QWebFrame* get_frame(QWebPage* page) const;
        QWebElement get_element_frame(QWebFrame* frame) const;
        QWebElement nth_child(QWebElement elm,int n) const;

        //special cases
        bool is_document;// = false;
        bool is_body;// = false;
        bool is_mainframe;// = false;
        bool m_invalid;


    };




}

#endif // DOMELEMENTDESCRIPTOR_H