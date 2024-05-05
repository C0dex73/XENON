#include <iostream>
using namespace std;

/*struct paths {
    private:
    char *xnn;
    char *schem;
    char *format(char *adr){

    }
    public:
    paths(char *xnn, char *schem=(char*)(' ')){
         
        if(schem == ""){ schem = xnn; }
    }
    char *getXnn(){ return this->xnn; }
    char *getSchem() { return this->schem; }
};*/

int main(int argc, char *argv[]) {
    if(argc < 2 || argc > 3) {
        fprintf(stderr, "No enough arguments, use the assembler like this : './assember.exe -\"program.xnn\" -\"schem.schematic\"' to compile the code of the xnn file into the schematic file.");
        return -1;
    }
    printf("okay");

    return 0;
}