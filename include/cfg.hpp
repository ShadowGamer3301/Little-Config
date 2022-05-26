#pragma once
#include <cstddef>
#include <fstream>
#include <map>
#include <string>

typedef std::map<std::string, std::string> CfgData;

//Function that loads data from specified file
//If everything was fine function will return true
//If some exception happend function will return false
inline bool LoadCfg(CfgData& data, std::string filepath)
{
    std::string line;
    
    std::string key, value;

    std::ifstream cfg_file(filepath.c_str());
    
    //Check if file exists
    if(cfg_file.is_open())
    {
        while(std::getline(cfg_file, line))
        {
            for(int i = 0; i < line.size(); i++)
            {
                if(line[i] == '=')
                {
                    for(int j = 0; j < i; j++)
                    {
                        key += line[j];
                    }
                    for(int j = i+1; j < line.size(); j++)
                    {
                        value += line[j];
                    }
                }
            }
            //Insert data to map
            data.emplace(key, value);

            //Clear local variables
            key = "";
            value = "";
        }
        return true;
    }
    else return false;
}