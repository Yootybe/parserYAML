#include "VisitorImp.h"


#include <iostream>
#include <vector>
#include <map>
#include <iterator>

#include <spdlog/spdlog.h> 

VisitorImp::VisitorImp()
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

        
    // YAMLobj* currentYamlObj = new YAMLobj;
    // baseYamlObj = currentYamlObj;
    // std::string key = this->inputSting.substr(startKeyPlace + 1, colonPlace - startKeyPlace - 1);
    std::cout << key << ":" << " ";

    baseYamlObj->key = key;
    baseYamlObj->nestLvl = nestLvl;
    // yamlVec.push_back(baseYamlObj);
    return std::make_pair(key, 0);
}

std::pair<std::string, int> VisitorImp::onParseStr(std::string& string)
{
    // std::string outStr;
    // int j = 0;
    // int i = startStr;
    
    // while(this->inputSting[i+1] != '"')
    // {
    //     outStr = outStr + this->inputSting[i];
    //     i++;
    //     j++;
    // }
    // outStr = outStr + this->inputSting[i] + '"';
    std::cout << string << " ";

    baseYamlObj->value = string;
    return std::make_pair("outStr", 0);
}

std::pair<std::string, int> VisitorImp::onParseNumber(std::string& number)
{
    // std::string outNumber;
    // int j = 0;
    // int i = startNumber;
    // while(i < this->inputSting.size())
    // {
    //     if (isspace(this->inputSting[i]))
    //     {
    //         // TODO: Infinity cycle if no space after number
    //         break;
    //     }
    //     outNumber = outNumber + this->inputSting[i];
    //     i++;
    //     j++;
    // }
    std::cout << number << " ";

    baseYamlObj->value = number;
    return std::make_pair("outNumber", 0);
}

std::pair<std::string, int> VisitorImp::onParseBool(std::string& boolean)
{
    // if (trueOrfalse == true)
    // {
    //     std::cout << "true ";
    //     baseYamlObj->value = "true";
    //     return std::make_pair("true", 0);
    // }
    // else if (trueOrfalse == false)
    // {
    //     std::cout << "false ";
    //     baseYamlObj->value = "false";
    //     return std::make_pair("false", 0);
    // }

    std::cout << boolean + " ";
    baseYamlObj->value = boolean;

    return std::make_pair("cum", 0);
}

std::pair<std::string, int> VisitorImp::onParseList(std::string& list)
{
    // int numberOfMembersInList = 0;
    // int colonPos = 0;
    // int i = startList;
    // bool isListAtEndOfFile = true;
    // for(i; i < this->inputSting.size(); i++)
    // {
    //     if(this->inputSting[i] == ':')
    //     {
    //         colonPos = i;
    //         isListAtEndOfFile = false;
    //         break;
    //     }
    // }

    // // TODO: Maybe don't need to know numberOfMembersInList
    // i = startList;
    // if (isListAtEndOfFile)
    // {
    //     for(i; i < this->inputSting.size(); i++)
    //     {
    //         if(this->inputSting[i] == '-')
    //         {
    //            numberOfMembersInList++;
    //         }
    //     }
    // }
    // else
    // {
    //     for(i; i < colonPos; i++)
    //     {
    //         if(this->inputSting[i] == '-')
    //         {
    //            numberOfMembersInList++;
    //         }
    //     }
    // }

    // std::string outAllList;
    // std::vector<std::string> listMembers;
    // std::string tempStr;

    // int numberInList = 1;
    // i = startList + 1;
    // for(i; i < this->inputSting.size(); i++)
    // {
    //     if (this->inputSting[i] == '-')
    //     {
    //         listMembers.push_back(tempStr);
    //         tempStr.clear();
    //         numberInList++;
    //         if (numberInList == numberOfMembersInList)
    //         {
    //             break;
    //         }
    //         continue;
    //     }

    //     if (!isspace(this->inputSting[i]))
    //     {
    //         tempStr += this->inputSting[i];
    //         // k++;
    //     }
    // }
    // listMembers.push_back(tempStr);

    // for (int k = 0; k < listMembers.size(); k++)
    // {
    //     outAllList += "- " + listMembers[k] + " ";
    // }

    std::cout << list;
    
    baseYamlObj->value = list;
    return std::make_pair("outAllList", 0);
}

void VisitorImp::onParseNest()
{
    
}

// void VisitorImp::onParseInt()
// {
    
// }

// void VisitorImp::onParseFloat()
// {
    
// }