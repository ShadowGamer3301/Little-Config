/*

    MIT License

    Copyright (c) 2022 ShadowGamer3301

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

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
    if (cfg_file.is_open())
    {
        while (std::getline(cfg_file, line))
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '=')
                {
                    for (int j = 0; j < i; j++)
                    {
                        key += line[j];
                    }
                    for (int j = i + 1; j < line.size(); j++)
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

inline std::string FindValue(const char* key, CfgData& data)
{
    CfgData::const_iterator pos = data.find(key);
    if (pos == data.end()) {
        return "";
    }
    else {
        std::string value = pos->second;
        return value;
    }
}
