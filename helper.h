#pragma once
#include <iostream>
#include <vector>
#include<random>
#include<numbers>
#include<cmath>

extern std::mt19937 rng;  
extern std::uniform_real_distribution<double> dist;

struct Node{
    float* weights;
    float output;
    float bias;
    float z;//value put in sigmod function
};
struct Layer{
    Node* nodes;
    int noOfNodes;
};
struct NeuralNetwork{
    Layer* layers;
    int noOfLayers;
};