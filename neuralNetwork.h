#include "helper.h"
#include "loader.h"
Layer setupLayersAfter1(Layer prevLayer,int noOfNodes);
float sigmoid(float x);
void feedforward(const Layer& prevLayer , Layer& currLayer);
Layer setupLayersAfter1(Layer prevLayer,int noOfNodes);
Layer setupLayer1(int noOfNodes , std::vector<int> inp);
NeuralNetwork setupNN(int noOfLayers,std::vector<int>nodesPerLayer,std::vector<int> input);
void backprop(const Layer& currLayer , Layer& prevLayer);