#ifndef DECORATOR_VISITOR_H
#define DECORATOR_VISITOR_H

#include "YAMLobj.h"
#include "Visitor.h"

#include <utility>
#include <string>
#include <spdlog/spdlog.h>

class DecoratorVisitor : public Visitor
{

protected:
    Visitor* visitor_;

public:

    DecoratorVisitor(Visitor* visitor) : visitor_(visitor) {}
    // std::string Operation() const override 
    // {
    //     return this->visitor->Operation();
    // }

    virtual std::pair<std::string, int> onParseKey(std::string& key, int nestLvl) override
    {
        spdlog::info("!");
        return this->visitor_->onParseKey(key, nestLvl);
    }




    // // virtual void onParseKeyStart(std::string& key, int nestLvl) = 0;
    // // virtual void onParseKeyEnd(std::string& key, int nestLvl) = 0;

    // // TODO: onParseKeyStart and onParseKeyEnd instead of onParseKey

    // virtual std::pair<std::string, int> onParseKey(std::string& key, int nestLvl) = 0;
    // virtual std::pair<std::string, int> onParseStr(std::string& string) = 0;
    // virtual std::pair<std::string, int> onParseNumber(std::string& number) = 0;
    // // virtual void onParseInt() = 0;
    // // virtual void onParseFloat() = 0;
    // virtual std::pair<std::string, int> onParseBool(std::string& boolean) = 0;
    // virtual std::pair<std::string, int> onParseList(std::string& list) = 0;
    // virtual void onParseNest() = 0;
    
};

#endif // DECORATOR_VISITOR_H