#include<iostream>
#include<vector>
#include<random>
#include<numbers>
#include<cmath>
struct Node{
    float* weights;
    float output;
    float bias;
    float z;//value put in sigmod function
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
float feedforward(Node& neuron , Layer& prevLayer){
    float sum = neuron.bias;
    for(int i=0;i<prevLayer.noOfNodes;i++){
        sum+=prevLayer.nodes[i].output * neuron.weights[i];
    }
    neuron.z=sums
    neuron.output=sigmoid(sum)
    return neuron.output;
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
    
}