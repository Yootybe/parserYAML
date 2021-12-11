#include "MyParser.h"
#include "Sink.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

MyParser::MyParser(Source* src) : src(src)
{

}

MyParser::~MyParser()
{
    
}

void MyParser::parse(Visitor* visitor)
{
    std::string inputString;
    src->read(inputString);
    if (inputString.size() == 0) 
    {
        std::cout << "Empty string" << std::endl;
    }

    if (inputString.substr(0, 3) != "---")
    {
        std::cout << "This is not YAML" << std::endl;
    }

    if (inputString.find(':') == std::string::npos) 
    {
        std::cout << "YAML is empty" << std::endl;
    }

    int spaceNotificator = 0;
    int spaceCounter = 0;
    int startString = 0;
    int nestCounter = 0;

    bool isCurrentNodeParent = true;

    for(int i = 3; i < inputString.size(); i++)
    {
        if (isspace(inputString[i]))
        {
            spaceNotificator = i;
            spaceCounter++;

            nestCounter = spaceCounter / 2;
        }

        if (inputString[i] == ':')
        {
            std::string key = inputString.substr(spaceNotificator + 1, i - spaceNotificator - 1);
            visitor->onParseKey(key, nestCounter);           

            isCurrentNodeParent = true;
            spaceCounter = 0;

            if (inputString[i+2] == 't')
            {
                // baseYamlObj->value = "true";
                i = i + 3;
                std::string tr = "true";
                visitor->onParseBool(tr);
                isCurrentNodeParent = false;
            }
            else if (inputString[i+2] == 'f')
            {
                // baseYamlObj->value = "false";
                i = i + 4;
                std::string fl = "false";
                visitor->onParseBool(fl);
                isCurrentNodeParent = false;
            }

            
            continue;
        }

        if (inputString[i] == '"')
        {
            std::string str;
            int j = 0;
            
            while(inputString[i+1] != '"')
            {
                str = str + inputString[i];
                i++;
                j++;
            }
            str = str + inputString[i] + '"';

            i++;
            std::pair<std::string, int> tmpPair = visitor->onParseStr(str);

            // baseYamlObj->value = visitor->onParseStr(i).first;
            // i = visitor->onParseStr(i).second;

            // baseYamlObj->value = tmpPair.first;
            // i = tmpPair.second;

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }

        if (isdigit(inputString[i]))
        {
            // std::pair<std::string, int> tmpPair = visitor->onParseNumber(i);
            // baseYamlObj->value = tmpPair.first;
            // i = tmpPair.second;

            // baseYamlObj->value = visitor->onParseNumber(i).first;
            // i = visitor->onParseNumber(i).second;

            std::string number;
            int j = 0;
            while(i < inputString.size())
            {
                if (isspace(inputString[i]))
                {
                    // TODO: Infinity cycle if no space after number
                    break;
                }
                number = number + inputString[i];
                i++;
                j++;
            }
            visitor->onParseNumber(number);
            i--;

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }

        if (inputString[i] == '-')
        {
            // std::pair<std::string, int> tmpPair = visitor->onParseList(i);
            // baseYamlObj->value = tmpPair.first;
            // i = tmpPair.second;

            // baseYamlObj->value = visitor->onParseList(i).first;
            // i = visitor->onParseList(i).second;

            int numberOfMembersInList = 0;
            int colonPos = 0;
            int startList = i;
            i = startList;
            bool isListAtEndOfFile = true;
            for(i; i < inputString.size(); i++)
            {
                if(inputString[i] == ':')
                {
                    colonPos = i;
                    isListAtEndOfFile = false;
                    break;
                }
            }

            // TODO: Maybe don't need to know numberOfMembersInList
            i = startList;
            if (isListAtEndOfFile)
            {
                for(i; i < inputString.size(); i++)
                {
                    if(inputString[i] == '-')
                    {
                    numberOfMembersInList++;
                    }
                }
            }
            else
            {
                for(i; i < colonPos; i++)
                {
                    if(inputString[i] == '-')
                    {
                    numberOfMembersInList++;
                    }
                }
            }

            std::string outAllList;
            std::vector<std::string> listMembers;
            std::string tempStr;

            int numberInList = 1;
            i = startList + 1;
            int spasesCounter = 0;
            for(i; i < inputString.size(); i++)
            {
                if (inputString[i] == '-')
                {
                    listMembers.push_back(tempStr);
                    tempStr.clear();
                    numberInList++;
                    // if (numberInList == numberOfMembersInList)
                    // {
                    //     break;
                    // }
                    continue;
                }

                if (!isspace(inputString[i]))
                {
                    tempStr = tempStr + inputString[i];
                    // k++;
                }

                if ((numberInList == numberOfMembersInList) && isspace(inputString[i]))
                {
                    spasesCounter++;
                    if (spasesCounter > 1){
                        break;
                    }
                    
                }
            }
            listMembers.push_back(tempStr);

            for (int k = 0; k < listMembers.size(); k++)
            {
                outAllList += "- " + listMembers[k] + " ";
            }

            spaceNotificator = i;

            visitor->onParseList(outAllList);

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }


        // YAMLobj* currentYamlObj = (YAMLobj*)malloc(sizeof(YAMLobj));
        // baseYamlObj = currentYamlObj;
    }

    // std::cout << std::endl << "Put 0 if you want out parsed as string" << std::endl << "Put 1 if you want out parsed string as file" << std::endl;

    // // true - string, false - file
    // bool inputType = false;
    // std::cin >> inputType;
    // Sink sink;
    
    // if (!inputType)
    // {
    //     sink.StringSink(yamlVector);
    // }
    // else
    // {
    //     sink.StreamSink(yamlVector);
    // }


    // std::cout << std::endl;

    // for (auto elem : yamlVector)
    // {
    //     std::string spaces = " ";
    //     for (int i = 0; i < elem->nestLvl; i++)
    //     {
    //         spaces = spaces + "  ";
    //     }
    //     std::cout << spaces << elem->key << ": " << elem->value << std::endl;
    // }



    // for (auto mapElem : yamlMap)
    // {
    //     std::string spaces = " ";
    //     for (int i = 0; i < mapElem.second->nestLvl; i++)
    //     {
    //         spaces = spaces + "  ";
    //     }
    //     std::cout << spaces << "Key " << mapElem.first;
    //     if (!mapElem.second->value.empty())
    //     {
    //         std::cout << " Elem: " << mapElem.second->value << std::endl;
    //     }
    //     std::cout << std::endl;

    // }

    // std::ofstream outYAML("some.yaml");

    // if (outYAML.is_open())
    // {
    //     outYAML << "---" << std::endl;
    // }
    

    // if (outYAML.is_open())
    // {
    //     outYAML.flush();
    //     outYAML.close();
    // }
}

// bool MyParser::isParseForSimpleTypes(std::vector<std::string>& fieldValueName, std::string& strBtwColon)
// {
//     if (strBtwColon.find('-') != std::string::npos)
//     {
//         // dash == -
//         std::vector<int> dashesPos;
//         for (int i = 0; i < strBtwColon.size(); i++) 
//         {
//             if (strBtwColon[i] == '-')
//             {
//                 dashesPos.push_back(i);
//             }
//         }
//         // parseList
//         fieldValueName = parseList(strBtwColon, dashesPos);
//         return true;
//     }
//     if (strBtwColon.find('"') != std::string::npos)
//     {
//         // parseStr
//         fieldValueName = parseStr(strBtwColon);
//         return true;
//     }
//     if (strBtwColon.find("true") != std::string::npos || strBtwColon.find("false") != std::string::npos)
//     {
//         // parseBool
//         fieldValueName = parseBool(strBtwColon);
//         return true;
//     }
//     if (strBtwColon.find('.') != std::string::npos)
//     {
//         // parseFloat
//         fieldValueName = parseFloat(strBtwColon);
//         return true;
//     }
//     else
//     {
//         // parseInt
//         fieldValueName = parseInt(strBtwColon);
//         if (!fieldValueName.size())
//         {
//             return false;
//         }
//         return true;
//     }
//     return false;
// }

// std::vector<std::string> MyParser::parseStr(std::string& parsingString)
// {
//     std::vector<std::string> fieldValueName;
//     std::string::size_type startString = parsingString.find('"');
//     std::string::size_type endString = parsingString.find('"', startString + 1);
//     std::string::size_type colonPos = parsingString.find(':');

//     fieldValueName.push_back(parsingString.substr(startString, endString - startString + 1));
//     fieldValueName.push_back(parsingString.substr(endString + 1, colonPos - endString + 1));

//     return fieldValueName;
// }

// std::vector<std::string> MyParser::parseBool(std::string& parsingString)
// {
//     std::vector<std::string> fieldValueName;

//     std::string::size_type boolPos = parsingString.find("true");
//     if (boolPos == std::string::npos)
//     {
//         boolPos = parsingString.find("false");
//     }

//     int spacePos = findSpaceInString(parsingString);
//     std::string::size_type colonPos = parsingString.find(':');

//     fieldValueName.push_back(parsingString.substr(boolPos, spacePos - boolPos));
//     fieldValueName.push_back(parsingString.substr(spacePos, colonPos - spacePos + 1));
    
//     return fieldValueName;
// }

// std::vector<std::string> MyParser::parseInt(std::string& parsingString)
// {
//     // TODO: check for numbers in parsingString
//     std::vector<std::string> fieldValueName;

//     std::string::size_type startString = 0;
//     int spacePos = findSpaceInString(parsingString);
//     if (spacePos == -1) 
//     {
//         return fieldValueName;
//     }
//     if (parsingString.substr(startString, spacePos - startString) == " ")
//     {
//         return fieldValueName;
//     }

//     std::string::size_type colonPos = parsingString.find(':');

//     fieldValueName.push_back(parsingString.substr(startString + 1, spacePos - startString - 1));
//     fieldValueName.push_back(parsingString.substr(spacePos, colonPos - spacePos + 1));
    
//     return fieldValueName;
// }

// std::vector<std::string> MyParser::parseFloat(std::string& parsingString)
// {
//     // TODO: check for numbers in parsingString
//     std::vector<std::string> fieldValueName;

//     std::string::size_type startString = 0;
//     int spacePos = findSpaceInString(parsingString);
//     std::string::size_type colonPos = parsingString.find(':');

//     fieldValueName.push_back(parsingString.substr(startString + 1, spacePos - startString - 1));
//     fieldValueName.push_back(parsingString.substr(spacePos, colonPos - spacePos + 1));
    
//     return fieldValueName;
// }


// std::vector<std::string> MyParser::parseList(std::string& parsingString, std::vector<int>& dashesPos)
// {
//     std::vector<std::string> fieldValueName;
//     fieldValueName.push_back("\n");
//     for (int i = 0; i < dashesPos.size() - 1; i++)
//     {
//         fieldValueName[0] += "   -" + parsingString.substr(dashesPos[i] + 1, dashesPos[i+1] - dashesPos[i] + -1) + "\n";
//     }

//     std::string::size_type colonPos = parsingString.find(':');

//     std::string tempStr = parsingString.substr(dashesPos.back() + 1, colonPos - dashesPos.back());
//     int spacePos = findSpaceInString(tempStr);
//     fieldValueName[0] += "   -" + tempStr.substr(0, spacePos);

//     colonPos = tempStr.find(':');
//     fieldValueName.push_back(tempStr.substr(spacePos, colonPos - spacePos + 1));
    
//     return fieldValueName;
// }

int findSpaceInString(std::string& inputStr)
{
    for (int i = 1; i < inputStr.size(); i++)
    {
        if (isspace(inputStr[i]))
        {
            return i;
        }
    }
    return -1;
}