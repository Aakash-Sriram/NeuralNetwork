#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "helper.h"
void loadweights(NeuralNetwork& nn, std::string filename);
bool hasData(std::string filename);
void loadbias(NeuralNetwork& nn,std::string filename);
int loadNoOfLayers(std::string filename);
std::vector<int> loadInput(std::string filename);
std::vector<int> loadNodesPerLayer(std::string filename);