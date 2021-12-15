#include "Parser.h"
#include "Visitor.h"
#include "Source.h"
#include "Sink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"
#include "Factories.h"


#include <iostream>
#include <fstream>
#include <string>
#include <memory>

int main()
{
    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    std::cout << "Put 0 if you don't want log process" << std::endl << "Put 1 if you want log process" << std::endl;

    bool loggingOn = false;
    std::cin >> loggingOn;
    std::cin.ignore(256, '\n');

    if (loggingOn)
    {
        sourceType = "logger";
        visitorType = "logger";
        parserType = "logger";
        sinkType = "logger";
    }

    std::cout << "Put 0 if you want put string to parse" << std::endl << "Put 1 if you want read file to parse" << std::endl;    

    // true - string, false - file
    bool inputType = false;
    std::cin >> inputType;
    std::cin.ignore(256, '\n');

    if (inputType)
    {
        sourceType = sourceType + "file";
    }
  
    Source* currentSource = makeSource(sourceType);

    std::cout << std::endl << "Put 0 if you want out parsed as string" << std::endl << "Put 1 if you want out parsed string as file" << std::endl;

    // true - string, false - file
    inputType = false;
    std::cin >> inputType;

    if (inputType)
    {
        sinkType = sinkType + "file";
    }

    Sink* sink = makeSink(sinkType);
    Visitor* firtsVisitorImp = makeVisitor(visitorType, sink);
    
    Parser* prs = makeParser(parserType, currentSource);
    prs->parse(firtsVisitorImp);

}

// --- sad: " dsasd" sadd: true someint: 32133 CUMING: - sus - amogsa - 228 dasasd: 323.2 dan: name: "DanD.Veloper" job: "Developer" team: "DevOps" dora: name: "DanD.Veloper" job: "Developer" teams: right: "DevOps" left: "Boss" front: "Sales" lol: "ss" sadd: true someint: 32133 CUMING: - sus - amogsa based: "nope"