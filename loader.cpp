#include "loader.h"
bool hasData(std::string filename){
    std::string line;
    std::ifstream inFile(filename);
    std::getline(inFile, line);
    if(line.empty()){
        std::cerr<<"Error: File "<<filename<<" is empty"<<std::endl;
        return false;
    }
    return true;
}
std::vector<std::string> customSplit(const std::string& str, const char delimiter=' ') {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()) { // Only add non-empty tokens
            tokens.push_back(token);
        }
    }

    return tokens;
}
float stringToFloat(const std::string& str) {
    try {
        float result = std::stof(str);
        return result;
    } catch (const std::invalid_argument&) {
        // Handle invalid argument exception.
    }
    
    // Default value if conversion fails or input is empty
    return 0.0f; 
}
void loadweights(NeuralNetwork& nn, std::string filename){
    std::ifstream inFile(filename);
    if(!inFile){
        std::cerr<<"Error: Could not open "<<filename<<std::endl;
        exit(1);
    }
    std::string line;
    if(!hasData(filename)){
        std::cout<<"prob";
    }else{
        std::getline(inFile, line);
    }
    std::vector<std::string> weightAsStrings = customSplit(line);
    std::vector<float> loadedWeights;
    for(auto& str: weightAsStrings){
        loadedWeights.push_back(stringToFloat(str));
    }

    int index=0;
    
    std::cout<<std::endl;
    for(int i=1;i<nn.noOfLayers;i++){
        for(int j=0;j<nn.layers[i].noOfNodes;j++){
        // nn.layers[i].nodes[j].weights = new float[nn.layers[i-1].noOfNodes];
            for(int k=0;k<nn.layers[i-1].noOfNodes;k++){
                nn.layers[i].nodes[j].weights[k]=loadedWeights[index++];
            }
        }
    }
}
