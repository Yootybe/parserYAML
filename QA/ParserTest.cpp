#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MyParser.h"

#include "Parser.h"
#include "Visitor.h"
#include "Source.h"
#include "Sink.h"
#include "DecoratorVisitor.h"
#include "DecoratorSource.h"
#include "DecoratorSink.h"
#include "DecoratorParser.h"
#include "Factories.h"
#include "VisitorImp.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class MockVisitor : public VisitorImp
{
public:
    MockVisitor(Sink* sink);
    ~MockVisitor();

    MOCK_METHOD2(onParseKey, std::pair<std::string, int> (std::string& key, int nestLvl));
    MOCK_METHOD1(onParseStr, std::pair<std::string, int> (std::string& string));
    MOCK_METHOD1(onParseNumber, std::pair<std::string, int> (std::string& number));
    MOCK_METHOD1(onParseBool, std::pair<std::string, int> (std::string& boolean));
    MOCK_METHOD1(onParseList, std::pair<std::string, int> (std::string& list));
    MOCK_METHOD0(onParseNest, void ());
    MOCK_METHOD0(onFinished, void ());
};

MockVisitor::MockVisitor(Sink* Sink) : VisitorImp(Sink)
{
    
}

MockVisitor::~MockVisitor()
{
    
}

TEST(ParserTest, trueTest) {

    std::string sourceType = "";
    std::string visitorType = "";
    std::string parserType = "";
    std::string sinkType = "";

    sourceType = sourceType + "file";
  
    Source* currentSource = makeSource(sourceType);

    Sink* sink = makeSink(sinkType);

    MockVisitor mockVisitor(sink);

    Parser* prs = makeParser(parserType, currentSource);

    // For string --- sad: " dsasd" sadd: true someint: 32133 dasasd: 323.2 dan:   name: "DanD.Veloper"   job: "Boss"     front: "Sales" lol: "ss" sadd: true someint: 32133

    EXPECT_CALL(mockVisitor, onParseKey).Times(11);
    EXPECT_CALL(mockVisitor, onParseStr).Times(5);
    EXPECT_CALL(mockVisitor, onParseNumber).Times(3);
    EXPECT_CALL(mockVisitor, onParseBool).Times(2);

    prs->parse(&mockVisitor);
}