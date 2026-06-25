#include<iostream>
#include<vector>
#include<random>
#include<numbers>
#include<cmath>
struct Node{
    float* w;
    float* x;
    float output;
    float bias;
    float res;//value put in sigmod function
}
struct Layer{
    Node* nodes;
    int noOfNodes;
}
struct NeuralNetwork{
    Layer* layers;
    int noOfLayers;
}
float sigmoid(float x){
    return (1.0f/(1,0f+std::exp(-x)));
}
std::vector<int> flatten(std::vector<std::vector<int>> input){
    vector<int> res;
    for(auto row:input){
        for(auto val:row){
            res.push_back(val);
        }
    }
    return res;
}
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;
    std::vector<std::vector<int>> X = {
        {1, 0},
        {0, 1},
        {1, 1},
        {0, 0}
    };

    //Print the input data
    for (auto x : X) {
        for (auto i : x) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
    // seed random numbers to make calculation
    std::mt19937 rng(1);  // Seed = 1
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    int hiddenlayers = 2;
    NeuralNetwork nn;
    nn.noOfLayers = hiddenlayers + 2; // input layer + hidden layers + output layer
    nn.layers = new Layer[nn.noOfLayers];

    arr = flatten(X);
    nn.layers[0].nodes = new Node[8]
    for(int i=0;i<8;i++){
        nn.layers[0].nodes[i].x=arr[i];
        nn.layers[0].nodes[i].w=dist(rng);
        nn.layers[0].nodes[i].bias=dist(rng);
    }

    for(int layer=1;layer<nn.noOfLayers;layer++){
        nn.layers[layer].noOfNodes = 2; // For simplicity each layer has 2 nodes
        nn.layers[layer].nodes = new Node[nn.layers[layer].noOfNodes];
        for(int i=0;i<nn.layers[layer].noOfNodes;i++){
            nn.layers.nodes[i].w= dist(rng);
            nn.layers.nodes[i].bias=dist(rng);
            for(int j=0;j<8;j++){
                temp = (nn.layers.nodes[j].w*nn.layers.nodes[j].x)
                nn.layers.nodes[i].x
            }
        }
    }
}
