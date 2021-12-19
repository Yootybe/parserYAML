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

    virtual std::pair<std::string, int> onParseKey(std::string& key, int nestLvl) override
    {
        // TODO: spdlog::info("onParseKey spdlog::info("onParseKey");");
        spdlog::info("onParseKey: " + key);
        return this->visitor_->onParseKey(key, nestLvl);
    }
    
    virtual std::pair<std::string, int> onParseStr(std::string& string) override
    {
        spdlog::info("onParseStr: " + string);
        return this->visitor_->onParseStr(string);
    }

    virtual std::pair<std::string, int> onParseNumber(std::string& number) override
    {
        spdlog::info("onParseNumber: " + number);
        return this->visitor_->onParseNumber(number);
    }

    virtual std::pair<std::string, int> onParseBool(std::string& boolean) override
    {
        spdlog::info("onParseBool: " + boolean);
        return this->visitor_->onParseBool(boolean);
    }

    virtual std::pair<std::string, int> onParseList(std::string& list) override
    {
        spdlog::info("onParseList: " + list);
        return this->visitor_->onParseList(list);
    }

    virtual void onFinished() override
    {
        spdlog::info("onFinished()");
        return this->visitor_->onFinished();
    }

    virtual void onParseNest() override
    {
        spdlog::info("!");
        return this->visitor_->onParseNest();
    }
};

#endif // DECORATOR_VISITOR_H