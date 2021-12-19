#include "VisitorImp.h"


#include <iostream>
#include <vector>
#include <map>
#include <iterator>

#include <spdlog/spdlog.h> 

VisitorImp::VisitorImp(Sink* Sink) : sink(Sink)
{
    
    baseYamlObj = new YAMLobj;
}

VisitorImp::~VisitorImp()
{
    
}

std::pair<std::string, int> VisitorImp::onParseKey(std::string& key, int nestLvl)
{

    if (nestLvl == 0)
    {
        YAMLobj* currentYamlObj = new YAMLobj;
        baseYamlObj = currentYamlObj;
        basedYamlObjs.insert(basedYamlObjs.begin(), baseYamlObj);
        yamlVec.push_back(baseYamlObj);
    }

    if (nestLvl > 0)
    {
        for (auto baseElem : basedYamlObjs)
        {
            if (baseElem->nestLvl == (nestLvl - 1))
            {
                YAMLobj* currentYamlObj = new YAMLobj;
                baseYamlObj = currentYamlObj;
                baseElem->nestedObjs.push_back(baseYamlObj);
                basedYamlObjs.insert(basedYamlObjs.begin(), baseYamlObj);
                break;
            }
        }
    }

    // std::cout << key << ":" << " ";

    baseYamlObj->key = key;
    baseYamlObj->nestLvl = nestLvl;
    return std::make_pair(key, 0);
}

std::pair<std::string, int> VisitorImp::onParseStr(std::string& string)
{
    // std::cout << string << " ";

    baseYamlObj->value = string;
    return std::make_pair("outStr", 0);
}

std::pair<std::string, int> VisitorImp::onParseNumber(std::string& number)
{
    // std::cout << number << " ";

    baseYamlObj->value = number;
    return std::make_pair("outNumber", 0);
}

std::pair<std::string, int> VisitorImp::onParseBool(std::string& boolean)
{
    // std::cout << boolean + " ";
    baseYamlObj->value = boolean;

    return std::make_pair("cum", 0);
}

std::pair<std::string, int> VisitorImp::onParseList(std::string& list)
{
    // std::cout << list;
    
    baseYamlObj->value = list;
    return std::make_pair("outAllList", 0);
}

void VisitorImp::onParseNest()
{
    
}

void VisitorImp::onFinished()
{
    sink->write(yamlVec);
}