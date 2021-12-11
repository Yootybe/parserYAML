#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <fstream>
#include <string>

class Source
{
public:

    virtual void read(std::string& generalString) = 0;
    
};

#endif // SOURCE_H