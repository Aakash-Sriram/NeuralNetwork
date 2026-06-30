#pragma once
#include "helper.h"
#include "loader.h"
#include <vector>
#include <string>

float sigmoid(float x);
Layer setupLayersAfter1(const Layer& prevLayer, int noOfNodes);
Layer setupLayer1(int noOfNodes, const std::vector<int>& inp);
NeuralNetwork setupNN(int noOfLayers,const std::vector<int>& nodesPerLayer,const std::vector<int>& input);
void feedforward(const Layer& prevLayer, Layer& currLayer);
// void backprop(const Layer& currLayer , Layer prevLayer);
void printModelDetails(const NeuralNetwork& nn,int extras=0);
NeuralNetwork loadModel(const std::string& filename);
float Loss(NeuralNetwork& nn,const std::vector<float>& expectedOutput);
float sigmoidDerivative(float output);
float YwrtZ(float output);
float LwrtY(float output, float expected);
float LwrtW(float output,float expected,float input);
void deltaLastLayer(Layer& last ,const std::vector<float>& expected);
// float deltaCalcExceptLast(const Layer& currLayer , Layer& layer);