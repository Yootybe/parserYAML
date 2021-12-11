#ifndef STRING_SINK_H
#define STRING_SINK_H

#include "YAMLobj.h"
#include "Sink.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void recWrite (YAMLobj* obj);

class StringSink : public Sink
{
public:

    StringSink();
    ~StringSink();

    void write(std::vector<YAMLobj*>& yamlVec) override;

};

StringSink::StringSink()
{

}

StringSink::~StringSink()
{
    
}

void StringSink::write(std::vector<YAMLobj*>& yamlVec)
{
    std::cout << std::endl;

    for (auto elem : yamlVec)
    {
        recWrite(elem);
    }
}


void recWrite (YAMLobj* obj)
{
    std::string spaces = " ";
    for (int i = 0; i < obj->nestLvl; i++)
    {
        spaces = spaces + "  ";
    }
    std::cout << spaces + obj->key << ": ";

    if (!obj->nestedObjs.empty())
    {
        std::cout << std::endl;
        for (auto nestElemet : obj->nestedObjs)
        {
            recWrite(nestElemet);
        }
    }
    else
    {
        std::cout << obj->value << std::endl;
    }
}


#endif // STRING_SINK_H