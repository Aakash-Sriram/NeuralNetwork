#include<iostream>
#include<vector>
#include<random>
#include<numbers>
#include<cmath>

std::mt19937 rng(1);  // Seed = 1
std::uniform_real_distribution<double> dist(0.0, 1.0);

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
float sigmoid(float x){
    return (1.0f/(1.0f+std::exp(-x)));
}
void feedforward(Node& neuron , Layer& prevLayer){
    float sum = neuron.bias;
    for(int i=0;i<prevLayer.noOfNodes;i++){
        sum+=prevLayer.nodes[i].output * neuron.weights[i];
    }
    neuron.z=sum;
    neuron.output=sigmoid(sum);
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
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;

    NeuralNetwork nn = setupNN(3,std::vector<int>{2,2,1},std::vector<int>{1,0});
    for(int i=1;i<nn.noOfLayers;i++){
        if(i==1){
            feedforward(nn.layers[0],nn.layers[i]);
        }else{
            feedforward(nn.layers[i-1],nn.layers[i]);
        }
    }
    for(int i=0;i<nn.layers[2].noOfNodes;i++){
        std::cout<<nn.layers[2].nodes[i].output<<" ";
    }

}

    // std::vector<std::vector<int>> X = {
    //     {1, 0},
    //     {0, 1},
    //     {1, 1},
    //     {0, 0}
    // };
    
    // //Print the input data
    // for (auto x : X) {
    //     for (auto i : x) {
    //         std::cout << i << " ";
    //     }
    //     std::cout << '\n';
    // }
    // nn.noOfLayers=3;
    // nn.layers = new Layer[nn.noOfLayers];//1 input 1 hidden 1 ouput
    // nn.layers[0].noOfNodes=2;
    // nn.layers[1].noOfNodes=2;
    // nn.layers[2].noOfNodes=1;
    
    // nn.layers[0].nodes = new Node[2];
    // nn.layers[1].nodes = new Node[2];
    // nn.layers[2].nodes = new Node[1];
    
    // nn.layers[0].nodes[0].output=X[0][0];
    // nn.layers[0].nodes[1].output=X[0][1];
    
    // for(int i=1;i<nn.noOfLayers;i++){
        //     for(int j=0;j<nn.layers[i].noOfNodes;j++){
            //         nn.layers[i].nodes[j].weights = new float[nn.layers[i-1].noOfNodes];
    //         for(int k=0;k<nn.layers[i-1].noOfNodes;k++){
    //             nn.layers[i].nodes[j].weights[k]=dist(rng);
    //         }
    //         nn.layers[i].nodes[j].bias=dist(rng);
    //         feedforward(nn.layers[i].nodes[j],nn.layers[i-1]);
    //         std::cout<<"z: "<<nn.layers[i].nodes[j].z<<std::endl;
    //         std::cout<<"output: "<<nn.layers[i].nodes[j].output<<" "<<std::endl;
    //     }
    // }