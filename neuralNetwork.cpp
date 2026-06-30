#include "neuralNetwork.h"
float sigmoid(float x){
    return (1.0f/(1.0f+std::exp(-x)));
}
Layer setupLayersAfter1(const Layer& prevLayer,int noOfNodes){
    Layer currLayer;
    currLayer.noOfNodes = noOfNodes;
    currLayer.nodes.resize(noOfNodes);
    for(int i=0;i<noOfNodes;i++){
        currLayer.nodes[i].bias=dist(rng);
        currLayer.nodes[i].weights.resize(prevLayer.noOfNodes);
        for(int j=0;j<prevLayer.noOfNodes;j++){
            currLayer.nodes[i].weights[j] = dist(rng);
        }
        currLayer.nodes[i].output = 0.0f;
        currLayer.nodes[i].z = 0.0f;
    }
    return currLayer;
}
Layer setupLayer1(int noOfNodes , const std::vector<int>& inp){
    Layer currLayer ;
    currLayer.noOfNodes = noOfNodes;
    currLayer.nodes.resize(noOfNodes);
    for(int i=0;i<noOfNodes;i++){
        currLayer.nodes[i].output=inp[i];
    }
    return currLayer;
}
NeuralNetwork setupNN(int noOfLayers,const std::vector<int>& nodesPerLayer,const std::vector<int>& input){
    if(nodesPerLayer[0]!=static_cast<int>(input.size())){
        std::cout<<"1st layer no of nodes != input";
        // exit(0);
    };
    NeuralNetwork nn;
    nn.noOfLayers = noOfLayers;
    nn.layers.resize(noOfLayers);
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
void printModelDetails(const NeuralNetwork& nn){
    std::cout<<nn.noOfLayers<<std::endl;
    for(int i=0;i<nn.noOfLayers;i++){
        Layer l = nn.layers[i];
        if(i==nn.noOfLayers-1){
            std::cout<<l.noOfNodes;
        }else{
            std::cout<<l.noOfNodes<<" ";
        }
    }
    std::cout<<std::endl;
    for(int i=0;i<nn.layers[0].noOfNodes;i++){
        if(i==nn.layers[0].noOfNodes-1){
            std::cout<<nn.layers[0].nodes[i].output;
        }else{
            std::cout<<nn.layers[0].nodes[i].output<<" ";
        }
    }
    std::cout<<std::endl;
    for(int i=1;i<nn.noOfLayers;i++){
        Layer l = nn.layers[i];
        for(int j=0;j<l.noOfNodes;j++){
            Node n = l.nodes[j];
            Layer prevLayer = nn.layers[i-1]; 
            for(int k=0;k<prevLayer.noOfNodes;k++){
                std::cout<<n.weights[k]<<" ";
            }
        }
    }
    std::cout<<std::endl;
    for(int i=1;i<nn.noOfLayers;i++){
        Layer l = nn.layers[i];
        for(int j=0;j<l.noOfNodes;j++){
            std::cout<<l.nodes[j].bias<<" ";
        }
    } 
}
NeuralNetwork loadModel(const std::string& filename){
    int noOfLayers = loadNoOfLayers(filename);
    std::vector<int> nodesPerLayer = loadNodesPerLayer(filename);
    std::vector<int> input = loadInput(filename);
    NeuralNetwork nn = setupNN(noOfLayers, nodesPerLayer, input);
    loadweights(nn, filename);
    loadbias(nn, filename);
    return nn;
}
float Loss(NeuralNetwork& nn,const std::vector<float>& expectedOutput){
    nn.Losses.resize(expectedOutput.size());
    Layer l = nn.layers[nn.noOfLayers-1];
    nn.Loss=0;
    for(int i=0;i<l.noOfNodes;i++){
        float outp = (l.nodes[i].output-expectedOutput[i]);
        nn.Losses[i]=0.5f*(outp*outp);
        nn.Loss+=nn.Losses[i];
    }
    return nn.Loss;
}
float sigmoidDerivative(float output)
{
    return output * (1.0f - output);
}
float ZwrtW(float input){
    std::cout<<input<<"\tDEBUG\n";
    return input;
    /*
    (∂z/∂w)​=x ​
    */
}
float YwrtZ(float output){
    std::cout<<output*(1.0f-output)<<"\tDEBUG\n";
    return(output*(1.0f-output));
    /*
    ∂y^∂z​​=y^​(1−y^​), y^ is predicted output 
    */
}
float LwrtY(float output,float expected){
    std::cout<<output-expected<<"\tDEBUG\n";
    return output-expected;
    /*
    ∂L/∂y^=y^−y
    */
}
float LwrtW(float output,float expected,float input){
    float o = (LwrtY(output,expected)*YwrtZ(output)*ZwrtW(input));
    std::cout<<o<<"\tDEBUG\n";
    return o;
}

void LOSSwrtB(){

}
