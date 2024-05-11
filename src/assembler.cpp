#include <iostream>
#include <string>
#include <vector>
#include "path_handler.h"

int main(int argc, char *_argv[]) {
    std::vector<std::string> argv(&_argv[1], &_argv[argc]);
    if(argc < 2 || argc > 3) {
        fprintf(stderr, "Not enough arguments, use the assembler like this : './assember.exe -\"program.xnn\" -\"schem.schematic\"' to compile the code of the xnn file into the schematic file.");
        return -1;
    }
    PathHandler paths = PathHandler(argv);
    std::cout << paths.getSchem() << "\r\n" << paths.getXnn() << "\r\n";
    return 0;
}
