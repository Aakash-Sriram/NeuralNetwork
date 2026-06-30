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
void printModelDetails(const NeuralNetwork& nn);
NeuralNetwork loadModel(const std::string& filename);
float Loss(NeuralNetwork& nn,const std::vector<float>& expectedOutput);
float sigmoidDerivative(float output);
float ZwrtW(float input);
float YwrtZ(float output);
float LwrtY(float output, float expected);
float LwrtW(float output,float expected,float input);
void LOSSwrtB();