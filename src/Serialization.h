#ifndef SERIALIZATION
#define SERIALIZATION

#include <string>

//Fetches the next property from the serialization string, returns it
//and erases it from the parameter
 std::string getNextProperty(std::string& serial);
 
 #endif