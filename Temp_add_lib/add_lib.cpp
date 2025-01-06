//#include <iostream>
#include <map>
#include <string>

#include "add_lib.h"

extern "C" __declspec(dllexport) void Country(std::string countryS) {
    
    std::map<std::string, std::string >  countryIP{
        {"Republic of Korea" , "221.147.27.204"} , {"Romania" , "217.138.212.58"},
        {"Viet Nam" , "222.255.11.117"} , {"China" , "119.97.247.62"} , {"Japan" , "219.100.37.117"}

    };


    
}