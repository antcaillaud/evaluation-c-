#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "sommets.h"

///La classe arête est construite à partir du nom du sommet père, du nom du sommet fils, et du poids de l'arête.
///Elle ne possède pas de méthodes particulières autres que les constructeurs, et la fonction d'affichage.
class Arete{
    friend class Liste;
    friend class Matrice;
    std::string pere;
    std::string fils;
    float poids;
    public:
    Arete();
    Arete(std::string pere,std::string fils, float poids);
    void print();
};