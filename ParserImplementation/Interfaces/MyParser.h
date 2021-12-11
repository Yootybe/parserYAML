#ifndef MYPARSER_H
#define MYPARSER_H

#include "Visitor.h"
#include "YAMLobj.h"
#include "Source.h"

#include <string>
#include <vector>
#include <memory>

class MyParser
{
public:
    MyParser(Source* src);
    ~MyParser();

    void parse(Visitor* visitor);

private:
    Source* src;
    
};

#endif // MYPARSER_H