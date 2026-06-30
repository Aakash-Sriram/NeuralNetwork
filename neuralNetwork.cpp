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
    if(nodesPerLayer[0]!=static_cast<int>(input.size())){
        std::cout<<"1st layer no of nodes != input";
        // exit(0);
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
void printModelDetails(NeuralNetwork& nn){
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
NeuralNetwork loadModel(std::string filename){
    int noOfLayers = loadNoOfLayers(filename);
    std::vector<int> nodesPerLayer = loadNodesPerLayer(filename);
    std::vector<int> input = loadInput(filename);
    NeuralNetwork nn = setupNN(noOfLayers, nodesPerLayer, input);
    loadweights(nn, filename);
    loadbias(nn, filename);
    return nn;
}


float ZwrtW(float weight,float input){
    std::cout<<ZwrtW(weight,input)<<"\tDEBUG\n";
    return input;
    /*
    (∂z/∂w)​=x ​
    */
}
float YwrtZ(float output){
    std::cout<<YwrtZ(output)<<"\tDEBUG\n";
    return(output*(1.0f-output));
    /*
    ∂y^∂z​​=y^​(1−y^​), y^ is predicted output 
    */
}
float LwrtY(float output,float expected){
    std::cout<<LwrtY(output,expected)<<"\tDEBUG\n";
    return output-expected;
}
float LwrtW(float output,float expected,float weight,float input){
    std::cout<<(LwrtY(output,expected)*YwrtZ(output)*ZwrtW(weight,input))<<"\tDEBUG\n";
    return(LwrtY(output,expected)*YwrtZ(output)*ZwrtW(weight,input));
}


void LOSSwrtB(){

}