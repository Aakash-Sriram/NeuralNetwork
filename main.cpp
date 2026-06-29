#include "neuralNetwork.h"
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;

    // NeuralNetwork nn = setupNN(3,std::vector<int>{2,2,2},std::vector<int>{1,0});
    // for(int i=1;i<nn.noOfLayers;i++){
    //     if(i==1){
    //         feedforward(nn.layers[0],nn.layers[i]);
    //     }else{
    //         feedforward(nn.layers[i-1],nn.layers[i]);
    //     }
    // }
    std::string modelFile = "./models/model1.txt";
    NeuralNetwork nn = setupNN(3,std::vector<int>{2,3,2},std::vector<int>{1,2});
    // loadweights(nn, modelFile);
    std::cout<<"\nweights"<<std::endl;
    for(int j=1;j<3;j++){
        for(int i=0;i<nn.layers[j].noOfNodes;i++){
            for(int k=0;k<nn.layers[j-1].noOfNodes;k++){
                std::cout<<nn.layers[j].nodes[i].weights[k]<<" ";
            }
        }
    }
}
// std::cout<<"\noutputs"<<std::endl;
// for(int j=0;j<3;j++){
//     for(int i=0;i<nn.layers[j].noOfNodes;i++){
//         std::cout<<nn.layers[j].nodes[i].output<<" ";
//     }
// }
// std::cout<<"\nZs"<<std::endl;
// for(int j=0;j<3;j++){
//     for(int i=0;i<nn.layers[j].noOfNodes;i++){
//         std::cout<<nn.layers[j].nodes[i].z<<" ";
//     }
// }
// std::cout<<"\nbias"<<std::endl;
// for(int j=0;j<3;j++){
//     for(int i=0;i<nn.layers[j].noOfNodes;i++){
//         std::cout<<nn.layers[j].nodes[i].bias<<" ";
//     }
// }