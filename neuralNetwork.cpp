#include "neuralNetwork.h"
float sigmoid(float x){
    return (1.0f/(1.0f+std::exp(-x)));
}
Layer setupLayersAfter1(Layer prevLayer,int noOfNodes){
    Layer currLayer;
    currLayer.noOfNodes = noOfNodes;
    currLayer.nodes = new Node[noOfNodes];
    for(int i=0;i<noOfNodes;i++){
        currLayer.nodes[i].bias=dist(rng);
        currLayer.nodes[i].weights = new float[prevLayer.noOfNodes];
        for(int j=0;j<prevLayer.noOfNodes;j++){
            currLayer.nodes[i].weights[j] = dist(rng);
        }
        currLayer.nodes[i].output = 0.0f;
        currLayer.nodes[i].z = 0.0f;
    }
    return currLayer;
}
Layer setupLayer1(int noOfNodes , std::vector<int> inp){
    Layer currLayer ;
    currLayer.noOfNodes = noOfNodes;
    currLayer.nodes = new Node[noOfNodes];
    for(int i=0;i<noOfNodes;i++){
        currLayer.nodes[i].output=inp[i];
    }
    return currLayer;
}
NeuralNetwork setupNN(int noOfLayers,std::vector<int>nodesPerLayer,std::vector<int> input){
    if(nodesPerLayer[0]!=input.size()){
        std::cout<<"1st layer no of nodes != input";
        exit(0);
    };
    NeuralNetwork nn;
    nn.noOfLayers = noOfLayers;
    nn.layers = new Layer[noOfLayers];
    nn.layers[0] = setupLayer1(input.size(),input);
    for(int i=1;i<noOfLayers;i++){
        nn.layers[i] = setupLayersAfter1(nn.layers[i-1],nodesPerLayer[i]);
    }
    return nn;
}
void feedforward(const Layer& prevLayer , Layer& currLayer){
    for(int i=0;i<currLayer.noOfNodes;i++){
        float sum = currLayer.nodes[i].bias;
        for(int j=0;j<prevLayer.noOfNodes;j++){
            sum += (prevLayer.nodes[j].output*currLayer.nodes[i].weights[j]);
        }
        currLayer.nodes[i].z=sum;
        currLayer.nodes[i].output=sigmoid(sum);
    }
}