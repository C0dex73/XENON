#include <string>
#include "string_processing.h"

bool utils::startsWith(std::string str, std::string prefix){
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}

bool utils::endsWith(std::string str, std::string suffix){
    return str.size() >= suffix.size() && str.compare(str.size()-suffix.size(), suffix.size(), suffix) == 0;
}