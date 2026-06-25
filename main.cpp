#include<iostream>
#include<vector>
int main(void){
    std::cout<<"Neural Network from ground up in C++ yo" << std::endl;
    std::vector<std::vector<int>> X = {
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}
    };
    for (auto x : X) {
        for (auto i : x) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
}