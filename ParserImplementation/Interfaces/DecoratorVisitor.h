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
        spdlog::info("!");
        return this->visitor_->onParseKey(key, nestLvl);
    }
    
};

#endif // DECORATOR_VISITOR_H