#ifndef XENON_PATH_HANDLER
#define XENON_PATH_HANDLER

#include <string>
#include <iostream>
#include <vector>

class PathHandler {
    private :
    std::string xnn;
    std::string schematic;
    std::string format(std::string adr, std::string ext);
    public :
    PathHandler(std::vector<std::string> argv);
    std::string getXnn();
    std::string getSchem();
};
#endif