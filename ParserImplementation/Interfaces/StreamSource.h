#ifndef STREAM_SOURCE_H
#define STREAM_SOURCE_H

#include "YAMLobj.h"
#include "Source.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StreamSource : public Source
{
public:

    StreamSource();
    ~StreamSource();

    void read(std::string& generalString) override;

};

StreamSource::StreamSource()
{

}

StreamSource::~StreamSource()
{
    
}

void StreamSource::read(std::string& generalString)
{
    std::ifstream file;
    file.open("D:\\Desktop\\sem1\\parsing_labs_cpp\\lb1\\src\\build\\bin\\fileToParse.yaml");
    if (file.is_open())
    {
        std::getline(file, generalString);
        file.close();
    }
}

#endif // STREAM_SOURCE_H