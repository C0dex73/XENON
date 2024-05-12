#include <string>
#include <vector>
#include <sstream>
#include "path_handler.h"
#include "string_processing.h"
#include "process_result.h"

std::string PathHandler::format(std::string adr, std::string ext){
    std::stringstream adr_;
    adr_ << adr << ext;
    return adr_.str();
}

PathHandler::PathHandler(std::vector<std::string> argv){
    if(argv.size() == 1){
        utils::ProcessResult<std::string> result = utils::safeSuffixRemove(argv[0], ".xnn");
        if(result.SEC != 0){
            result = utils::safeSuffixRemove(argv[0], ".xas");
        }
        argv.insert(argv.end(), {result.res, result.res});
        argv.erase(argv.begin());
    }else{
        argv[0] = utils::safeSuffixRemove(argv[0], ".xnn").res;
        argv[1] = utils::safeSuffixRemove(argv[1], ".xas").res;
    }
    this->xnn = format(argv[0], std::string(".xnn"));
    this->schematic = format(argv[1], std::string(".xas"));
}

std::string PathHandler::getXnn(){
    return this->xnn;
}

std::string PathHandler::getSchem(){
    return this->schematic;
}