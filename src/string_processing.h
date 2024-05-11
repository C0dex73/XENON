#ifndef XENON_STRING_PROCESSING
#define XENON_STRING_PROCESSING

#include <string>

namespace utils {
    bool startsWith(std::string str, std::string prefix);
    bool endsWith(std::string str, std::string suffix);
}

#endif