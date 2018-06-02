#include "Serialization.h"

 std::string getNextProperty(std::string& serial)
{
    //Find the index of the first colon, in the meantime keep adding characters
    //to the substring

    unsigned int index = 0;
    std::string result;
    while (true) {
        if (serial[index] == ':')
        {
            break;
        }
        else 
        {
            result += serial[index];
        }
    };
    serial.erase(0, result.size() + 1);
    return result;
}