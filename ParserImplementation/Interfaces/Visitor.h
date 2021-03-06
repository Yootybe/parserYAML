#ifndef VISITOR_H
#define VISITOR_H

#include "YAMLobj.h"
#include "Sink.h"

#include <utility>
#include <string>

class Visitor
{
public:


    virtual std::pair<std::string, int> onParseKey(std::string& key, int nestLvl) = 0;
    virtual std::pair<std::string, int> onParseStr(std::string& string) = 0;
    virtual std::pair<std::string, int> onParseNumber(std::string& number) = 0;
    // virtual void onParseInt() = 0;
    // virtual void onParseFloat() = 0;
    virtual std::pair<std::string, int> onParseBool(std::string& boolean) = 0;
    virtual std::pair<std::string, int> onParseList(std::string& list) = 0;
    virtual void onParseNest() = 0;

    virtual void onFinished() = 0;

    virtual ~Visitor() {};
    
};

#endif // VISITOR_H