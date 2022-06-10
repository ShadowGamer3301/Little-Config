# Little-Config
C++ header only library for opening .cfg files

## About project
Little config is simple header only library that allows to read configurations in a simple way. This project was tested out using C++20 but should work with both C++14 and C++17. Little config uses only standard c++ library so it will work on every major platform. 

## Supported formats
.cfg

## Examples
```C++
    CfgData data;

    LoadCfg(data, "test.cfg");

    for(auto const &pair : data)
    {
        std::cout << "Key: " << pair.first << " Value: " << pair.second << std::endl;
    }
```
