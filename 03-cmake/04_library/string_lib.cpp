#include "string_lib.hpp"
#include <iostream>
std::vector<std::string> split(const std::string& text, const char delimiter)
{
    std::vector<std::string> result;
    std::string temp_str;
    for(auto c : text){
        if(c == delimiter){
            if(!temp_str.empty()){
                result.push_back(temp_str);
                temp_str.clear();
            }
        }
        else{
            temp_str.push_back(c);
        }
    }
    if(!temp_str.empty())
        result.push_back(temp_str);

    return result;
}

