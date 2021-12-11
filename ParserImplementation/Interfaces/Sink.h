#ifndef SINK_H
#define SINK_H

#include "YAMLobj.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Sink
{
public:

    virtual void write(std::vector<YAMLobj*>& yamlVec) = 0;

};

#endif // SINK_H