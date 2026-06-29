#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "helper.h"
std::vector<float> loadweights(std::string filename){
    std::ifstream inFile(filename);
    if(!inFile){
        std::cerr<<"Error: Could not open "<<filename<<std::endl;
        exit(1);
    }
    std::string line;
    std::getline(inFile, line);
    if(line.empty()){
        std::cerr<<"Error: File "<<filename<<" is empty"<<std::endl;
        exit(1);
    }
    std::stringstream ss(line);
    
    std::vector<float> weights(
        (std::istream_iterator<float>(ss)),
        std::istream_iterator<float>()
    );

    return weights;
}