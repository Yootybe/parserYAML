#ifndef VISITORIMP_H
#define VISITORIMP_H

#include "Visitor.h"
#include "YAMLobj.h"

#include <string>
#include <vector>

class VisitorImp : public Visitor 
{
public:
    VisitorImp();
    ~VisitorImp();

    std::string inputSting;
// protected:
    
    std::pair<std::string, int> onParseKey(std::string& key, int nestLvl) override;
    std::pair<std::string, int> onParseStr(std::string& string) override;
    std::pair<std::string, int> onParseNumber(std::string& number) override;
    // void onParseInt() override;
    // void onParseFloat() override;
    std::pair<std::string, int> onParseBool(std::string& boolean) override;
    std::pair<std::string, int> onParseList(std::string& list) override;
    void onParseNest() override;

    std::vector<YAMLobj*> basedYamlObjs;
    std::vector<YAMLobj*> yamlVec;
    YAMLobj* baseYamlObj;


};

#endif // VISITORIMP_H