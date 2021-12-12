#ifndef DECORATOR_PARSER_H
#define DECORATOR_PARSER_H

#include "Parser.h"

#include <spdlog/spdlog.h>

class DecoratorParser : public Parser
{

protected:
    Parser* parser_;

public:

    DecoratorParser(Parser* parser) : parser_(parser) {}

    virtual void parse(Visitor* visitor) override
    {
        spdlog::info("Parser start");
        return this->parser_->parse(visitor);
    }
    
};

#endif // DECORATOR_PARSER_H