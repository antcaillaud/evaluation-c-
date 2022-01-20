#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "arete.h"

Arete::Arete():pere(""), fils(""), poids(0){}

Arete::Arete(std::string pere,std::string fils, float poids):
    pere(pere), fils(fils), poids(poids){}

void Arete::print(){
    if (pere != ""){
        std::cout<< "   "<< poids<< std::endl<< pere << " -> " << fils << std::endl;
    } 
}