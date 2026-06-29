#include "helper.h"
#include "loader.h"
float sigmoid(float x);
Layer setupLayersAfter1(Layer prevLayer,int noOfNodes);
Layer setupLayer1(int noOfNodes , std::vector<int> inp);
NeuralNetwork setupNN(int noOfLayers,std::vector<int>nodesPerLayer,std::vector<int> input);
void feedforward(const Layer& prevLayer , Layer& currLayer);
void printModelDetails(NeuralNetwork& nn);
NeuralNetwork loadModel(std::string filename);
void backprop(const Layer& currLayer , Layer& prevLayer);