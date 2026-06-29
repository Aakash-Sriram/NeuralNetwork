#include "neuralNetwork.h"
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;

    std::string modelFile = "./models/model1.txt";

    // NeuralNetwork nn = setupNN(3,std::vector<int>{2,3,2},std::vector<int>{1,0});
    NeuralNetwork nn = loadModel(modelFile);
    printModelDetails(nn);
}