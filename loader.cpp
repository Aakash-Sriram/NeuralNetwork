#include "loader.h"
int main(){
    std::vector<float> weights = loadweights("models/model1.txt");
    for(float w : weights){
        std::cout<<w<<" ";
    }
    std::cout<<std::endl;
    return 0;
}