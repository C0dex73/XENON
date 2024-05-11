#include <string>
#include <iostream>
#include <vector>
#include "path_handler.h"
#include "string_processing.h"

std::string PathHandler::format(std::string adr, std::string ext){
    if(adr.length() < ext.length() || (adr.length() == ext.length() && adr != ext) || adr.substr(adr.length()-ext.length()-1) != ext){
        adr.append(ext);
    }
    return adr;
}

PathHandler::PathHandler(std::vector<std::string> argv){
    if(argv.size() == 1){
        if(utils::endsWith(argv[0], std::string(".xnn"))){
            argv[0].erase(argv[0].length()-4);
        }
        argv.push_back(argv[0]);
    }
    this->xnn = format(argv[0], std::string(".xnn"));
    this->schematic = format(argv[1], std::string(".schematic"));
}

std::string PathHandler::getXnn(){
    return this->xnn;
}

std::string PathHandler::getSchem(){
    return this->schematic;
}