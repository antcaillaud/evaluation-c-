#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "matrice.h"


///La classe Liste possède comme la classe Matrice d'un élément de la classe Sommets.
///Elle possède surtout un dictionnaire qui à chaque nom va associer un dictionnaire 
///contenant en clé le nom des voisins et en valeur le poids de l'arête.

class Liste{
    friend class Matrice;
    Sommets sommets;
    std::map<std::string,std::map<std::string, float>> liste;
    public:
    Liste(const std::vector<Arete>& v,const Sommets& sommets);
    void print_voisins(std::string a); ///Affiche les arêtes partant du sommet a
    std::vector<Arete> voisins(std::string a); ///Vecteur d'arête partant du sommet a
    void print();
    Matrice Liste_to_Matrice();
    void parcours_prof_rec_liste(std::string start, std::vector<bool>& Vu);
    void parcours_prof_rec_liste_final(std::string start);
    std::vector<bool> parcours_prof_iter_liste(std::string start, std::vector<bool>& Vu);
    void parcours_prof_iter_liste_final(std::string start);
    void parcours_large_iter_liste(std::string start, int i);
};
