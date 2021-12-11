#ifndef STREAM_SINK_H
#define STREAM_SINK_H

#include "YAMLobj.h"
#include "Sink.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void recWriteStream (YAMLobj* obj, std::string& fileStr);

class StreamSink : Sink
{
public:

    StreamSink();
    ~StreamSink();

    void write(std::vector<YAMLobj*>& yamlVec) override;

};

StreamSink::StreamSink()
{

}

StreamSink::~StreamSink()
{
    
}

void StreamSink::write(std::vector<YAMLobj*>& yamlVec)
{
    std::string fileStr = "--- \n";
    
    for (auto elem : yamlVec)
    {
        recWriteStream(elem, fileStr);
    }

    std::ofstream outFile("outYAML.yaml");
    if (outFile.is_open())
    {
        outFile << fileStr;
    }
}

void recWriteStream (YAMLobj* obj, std::string& fileStr)
{

    std::string spaces = " ";
    for (int i = 0; i < obj->nestLvl; i++)
    {
        spaces = spaces + "  ";
    }
    fileStr = fileStr + spaces + obj->key + ": ";

    if (!obj->nestedObjs.empty())
    {
        fileStr = fileStr + "\n";
        for (auto nestElemet : obj->nestedObjs)
        {
            recWriteStream(nestElemet, fileStr);
        }
    }
    else
    {
        fileStr = fileStr + obj->value + "\n";
    }
    
}

#endif // STREAM_SINK_H