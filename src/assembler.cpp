#include <iostream>
#include <string>
#include <vector>
#include "path_handler.h"

int main(int argc, char *_argv[]) {
    std::vector<std::string> argv(&_argv[1], &_argv[argc]);
    if(argc < 2 || argc > 3) {
        fprintf(stderr, "Not enough arguments, use the assembler like this : './assember.exe -\"program.xnn\" -\"assemblyfile.xas\"' to compile the code of the xnn file into the assembly file.");
        return 11;
    }
    PathHandler paths = PathHandler(argv);
    return 0;
}
