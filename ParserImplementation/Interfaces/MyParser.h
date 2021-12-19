#ifndef MYPARSER_H
#define MYPARSER_H

#include "Visitor.h"
#include "YAMLobj.h"
#include "Source.h"
#include "Parser.h"

#include <string>
#include <vector>
#include <memory>

class MyParser : public Parser
{
public:
    MyParser(Source* src);
    ~MyParser();

    bool parse(Visitor* visitor) override;

private:
    Source* src;
    
};

#endif // MYPARSER_H