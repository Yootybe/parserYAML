#ifndef PARSER_H
#define PARSER_H

#include "Visitor.h"
#include "YAMLobj.h"
#include "Source.h"

#include <string>
#include <vector>
#include <memory>

class Parser
{
public:
    
    virtual bool parse(Visitor* visitor) = 0;
    
};

#endif // PARSER_H