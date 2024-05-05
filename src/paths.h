#ifndef XNN_SCHEM_PATHS
#define XNN_SCHEM_PATHS

struct Paths {
    private:
    char *xnn;
    char *schem;
    char *format(char *adr, char *extension){
        if(adr+strlen(adr)-strlen(extension) != extension){
            return strcat(adr, extension);
        }
        return adr;
    }
    char *err;
    public:
    Paths(int argc, char *argv[]){
        this->err = (char *)"";
        if(argc == 2){
            int length = sizeof(argv[1])*strlen(argv[1]);
            char *schematic = (char *)malloc(length);
            memcpy(schematic, argv[1], length);
            this->schem = this->format(schematic, (char *)".schematic");
        }else{
            this->schem = this->format(argv[2], (char *)".schematic");
        }
        this->xnn = this->format(argv[1], (char *)".xnn");
    }
    char *getXnn(){ return this->xnn; }
    char *getSchem() { return this->schem; }
    char *getErr() { return this->err; }
};

#endif