#pragma once
#include <iostream>
#include <vector>
#include "arete.h"

///déclaration au préalable de la classe Liste qui est utilisée dans la classe matrice.
class Liste;

///La classe Matrice est composée d'un vecteur de vecteur de flotant et d'un élément de la classe Sommets
/// qui permet d'assurer la correspondance entre nom et indices.
class Matrice{
    friend class Liste;
    std::vector<std::vector<float>> mat;
    Sommets sommets;
    public:
    Matrice();
    Matrice(Sommets sommets);
    Matrice(Sommets sommets, std::vector<std::vector<float>> mat);
    Matrice(const std::vector<Arete>& v, Sommets sommets);
    void print();
    Liste Matrice_to_Liste();
    std::vector<Arete> voisins(int i); ///Vecteur d'arête partant du sommet a
    void parcours_prof_rec_matrice(int i, std::vector<bool>& Vu);
    void parcours_prof_rec_matrice_final(int i);
    std::vector<bool> parcours_prof_iter_matrice(int i, std::vector<bool>& Vu);
    void parcours_prof_iter_matrice_final(int i);
    void parcours_large_iter_matrice(int i, int k);
    std::pair<Matrice,std::vector<std::vector<std::vector<Arete>>>> Floyd_Warshall();
};