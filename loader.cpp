#include "loader.h"
int WEIGHT_LINE=4;
int BIAS_LINE=5;
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
void getThatLine(int lineNo,std::string& line,std::string filename){
    std::ifstream inFile(filename);
    if(!inFile){
        std::cerr<<"Error: Could not open "<<filename<<std::endl;
        exit(1);
    }
    if(!hasData(filename)){
        std::cout<<"prob";
    }else{
        int curr=1;
        while(curr<=lineNo){
            std::getline(inFile, line);
            curr++;
        }
    }
}
void loadweights(NeuralNetwork& nn, std::string filename){
    std::string line;
    getThatLine(WEIGHT_LINE,line,filename); 
    std::vector<std::string> weightAsStrings = customSplit(line);
    std::vector<float> loadedWeights;
    for(auto& str: weightAsStrings){
        loadedWeights.push_back(stringToFloat(str));
    }
    int index=0;
    std::cout<<std::endl;
    for(int i=1;i<nn.noOfLayers;i++){
        for(int j=0;j<nn.layers[i].noOfNodes;j++){
            for(int k=0;k<nn.layers[i-1].noOfNodes;k++){
                nn.layers[i].nodes[j].weights[k]=loadedWeights[index++];
            }
        }
    }
}
void loadbias(NeuralNetwork& nn,std::string filename){
    std::string line;
    getThatLine(BIAS_LINE,line,filename); 
    std::vector<std::string> biasAsStrings = customSplit(line);
    std::vector<float> loadedBias;
    for(auto& str: biasAsStrings){
        loadedBias.push_back(stringToFloat(str));
    }

    int index=0;
    std::cout<<std::endl;
    for(int i=1;i<nn.noOfLayers;i++){
        for(int j=0;j<nn.layers[i].noOfNodes;j++){
            nn.layers[i].nodes[j].bias=loadedBias[index++];
        }
    }
}
int loadNoOfLayers(std::string filename){
    std::string line;
    getThatLine(1,line,filename);
    return std::stoi(line);
}
std::vector<int> loadNodesPerLayer(std::string filename){
    std::string line;
    getThatLine(2,line,filename);
    std::vector<std::string> nodesAsStrings = customSplit(line);
    std::vector<int> nodesPerLayer;
    for(auto& str: nodesAsStrings){
        nodesPerLayer.push_back(std::stoi(str));
    }
    return nodesPerLayer;
}
std::vector<int> loadInput(std::string filename){
    std::string line;
    getThatLine(3,line,filename);
    std::vector<std::string> inputAsStrings = customSplit(line);
    std::vector<int> input;
    for(auto& str: inputAsStrings){
        input.push_back(std::stoi(str));
    }
    return input;
}