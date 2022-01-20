#pragma once
#include <iostream>
#include <map>


///La classe Sommets sert uniquement à associer les noms et les indices des sommets.
///Cela permet notamment de passer d'une représentation à une autre.
class Sommets{
    public:
    std::map<std::string, int> dict;
    std::map<int, std::string> dictbis;
    Sommets();
    Sommets(std::map<std::string, int> dict, std::map<int, std::string> dictbis);
};