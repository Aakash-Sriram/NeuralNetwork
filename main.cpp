#include "neuralNetwork.h"

int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;

    NeuralNetwork nn = setupNN(3,std::vector<int>{2,2,2},std::vector<int>{1,0});
    for(int i=1;i<nn.noOfLayers;i++){
        if(i==1){
            feedforward(nn.layers[0],nn.layers[i]);
        }else{
            feedforward(nn.layers[i-1],nn.layers[i]);
        }
    }
    std::cout<<"\noutputs"<<std::endl;
    for(int j=0;j<3;j++){
        for(int i=0;i<nn.layers[j].noOfNodes;i++){
            std::cout<<nn.layers[j].nodes[i].output<<" ";
        }
    }
    std::cout<<"\nZs"<<std::endl;
    for(int j=0;j<3;j++){
        for(int i=0;i<nn.layers[j].noOfNodes;i++){
            std::cout<<nn.layers[j].nodes[i].z<<" ";
        }
    }
    std::cout<<"\nbias"<<std::endl;
    for(int j=0;j<3;j++){
        for(int i=0;i<nn.layers[j].noOfNodes;i++){
            std::cout<<nn.layers[j].nodes[i].bias<<" ";
        }
    }
    std::cout<<"\nweights"<<std::endl;
    for(int j=1;j<3;j++){
        for(int i=0;i<nn.layers[j].noOfNodes;i++){
            for(int k=0;k<nn.layers[j-1].noOfNodes;k++){
            std::cout<<nn.layers[j].nodes[i].weights[k]<<" ";
            }
        }
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