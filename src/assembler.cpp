#include <iostream>
#include <cstring>
#include "paths.h"
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2 || argc > 3) {
        fprintf(stderr, "Not enough arguments, use the assembler like this : './assember.exe -\"program.xnn\" -\"schem.schematic\"' to compile the code of the xnn file into the schematic file.");
        return -1;
    }
    
    Paths paths(argc, argv);
    if(paths.getErr() != ""){
        fprintf(stderr, paths.getErr());
        return -1;
    }
    cout << paths.getXnn() << " --> " << paths.getSchem();
    return 0;
}