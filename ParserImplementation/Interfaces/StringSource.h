#ifndef STRING_SOURCE_H
#define STRING_SOURCE_H

#include "YAMLobj.h"
#include "Source.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StringSource : public Source
{
public:

    StringSource();
    ~StringSource();

    void read(std::string& generalString) override;

};

inline StringSource::StringSource()
{

}

inline StringSource::~StringSource()
{
    
}

inline void StringSource::read(std::string& generalString)
{
    std::getline(std::cin, generalString);
}

#endif // STRING_SOURCE_H