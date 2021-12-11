#include "MyParser.h"
#include "Visitor.h"
#include "VisitorImp.h"
#include "Source.h"
#include "Sink.h"
#include "StreamSource.h"
#include "StreamSink.h"
#include "StringSource.h"
#include "StringSink.h"
#include "DecoraterVisitor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

int main()
{
    std::cout << "Put 0 if you want put string to parse" << std::endl << "Put 1 if you want read file to parse" << std::endl;

    // true - string, false - file
    bool inputType = false;
    std::cin >> inputType;
    std::cin.ignore(256, '\n');
    
    Source* currentSource;
    
    if (!inputType)
    {
        currentSource = new StringSource;
    }
    else
    {
        currentSource = new StreamSource;
    }

    VisitorImp firtsVisitorImp;
    MyParser parser(currentSource);
    parser.parse(&firtsVisitorImp);

    std::cout << std::endl << "Put 0 if you want out parsed as string" << std::endl << "Put 1 if you want out parsed string as file" << std::endl;

    // true - string, false - file
    inputType = false;
    std::cin >> inputType;
    
    if (!inputType)
    {
        StringSink stringSink;
        stringSink.write(firtsVisitorImp.yamlVec);
    }
    else
    {
        StreamSink streamSink;
        streamSink.write(firtsVisitorImp.yamlVec);
    }
}

// --- sad: " dsasd" sadd: true someint: 32133 CUMING: - sus - amogsa - 228 dasasd: 323.2 dan: name: "DanD.Veloper" job: "Developer" team: "DevOps" dora: name: "DanD.Veloper" job: "Developer" teams: right: "DevOps" left: "Boss" front: "Sales" lol: "ss" sadd: true someint: 32133 CUMING: - sus - amogsa based: "nope"