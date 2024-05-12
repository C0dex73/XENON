#ifndef XENON_PROCESS_RESULT
#define XENON_PROCESS_RESULT

namespace utils {
    template <class T> struct ProcessResult {
        int SEC;
        T res;
    };
}

#endif