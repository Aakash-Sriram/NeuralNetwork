#pragma once
#include <iostream>
#include <vector>
#include<random>
#include<numbers>
#include<cmath>

extern std::mt19937 rng;  
extern std::uniform_real_distribution<double> dist;

struct Node{
    std::vector<float> weights;
    float output;
    float bias;
    float z;//value put in sigmod function
    float delta;
};
struct Layer{
    std::vector<Node> nodes;
    int noOfNodes;
};
struct NeuralNetwork{
    std::vector<Layer> layers;
    int noOfLayers;
    std::vector<float> Losses;
    float Loss;
};