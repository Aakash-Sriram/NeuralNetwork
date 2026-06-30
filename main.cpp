#include "neuralNetwork.h"
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;

    const std::string& modelFile = "./models/model1.txt";

    // NeuralNetwork nn = setupNN(3,std::vector<int>{2,2,1},std::vector<int>{1,0});
    NeuralNetwork nn = loadModel(modelFile);
    for(int i=1;i<nn.noOfLayers;i++){
        feedforward(nn.layers[i-1],nn.layers[i]);
    }
    deltaLastLayer(nn.layers[nn.noOfLayers-1],std::vector<float>{0.5f});
    printModelDetails(nn,1);
}