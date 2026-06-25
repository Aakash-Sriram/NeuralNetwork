#include<iostream>
#include<vector>
#include<random>
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
void sigmoid();
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;
    std::vector<std::vector<int>> X = {
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}
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

}
