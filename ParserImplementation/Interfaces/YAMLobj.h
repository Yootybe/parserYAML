#ifndef YAML_OBJ_H
#define YAML_OBJ_H


#include <string>
#include <vector>

class YAMLobj 
{
public:
    YAMLobj();
    ~YAMLobj();

    std::vector<YAMLobj*> nestedObjs;
    std::string key;
    std::string value;
    int nestLvl = 0;
};

#endif // YAML_OBJ_H