#include <string>
#include "string_processing.h"
#include "process_result.h"

utils::ProcessResult<bool> utils::startsWith(std::string str, std::string prefix){
    utils::ProcessResult<bool> res;
    res.res = str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
    res.SEC = 0;
    return res;
}

utils::ProcessResult<bool> utils::endsWith(std::string str, std::string suffix){
    utils::ProcessResult<bool> res;
    res.res = str.size() >= suffix.size() && str.compare(str.size()-suffix.size(), suffix.size(), suffix) == 0;
    res.SEC = 0;
    return res;
}

utils::ProcessResult<std::string> utils::safeSuffixRemove(std::string str, std::string suffix){
    std::string _str = str;
    utils::ProcessResult<std::string> res;
    res.res = utils::endsWith(str, suffix).res ? str.erase(str.length()-suffix.length()) : str;
    res.SEC = res.res == _str ? 87 : 0;
    return res;
}