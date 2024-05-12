#ifndef XENON_STRING_PROCESSING
#define XENON_STRING_PROCESSING

#include <string>
#include "process_result.h"

namespace utils {
    ProcessResult<bool> startsWith(std::string str, std::string prefix);
    ProcessResult<bool> endsWith(std::string str, std::string suffix);
    ProcessResult<std::string> safeSuffixRemove(std::string str, std::string suffix);
}

#endif