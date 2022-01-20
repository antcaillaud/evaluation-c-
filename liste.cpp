#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "liste.h"

std::map<std::string,std::map<std::string, float>> liste_vide {};




///Question 1 : Implémentation des méthodes de la classe Liste:
Liste::Liste(const std::vector<Arete>& v,const Sommets& sommets):
    liste(liste_vide),sommets(sommets)
    {for(Arete a: v){
        if ((liste.find(a.pere) == liste.end())){
            std::map<std::string, float> b {{a.fils, a.poids}};
            liste[a.pere] = b;
        }
        else{
            liste[a.pere][a.fils] = a.poids;
        }    
    }}

void Liste::print_voisins(std::string a){
    std::map<std::string, float> voisins = liste[a];
    for (auto p: voisins){
        Arete k {a, p.first, p.second};
        k.print();
    }
}

std::vector<Arete> Liste::voisins(std::string a){
    std::map<std::string, float> voisins = liste[a];
    std::vector<Arete> res;
    for (auto p: voisins){
        Arete k {a, p.first, p.second};
        res.push_back(k);
    }
    return res;
}

void Liste::print(){
    for(auto p: liste){
        std::cout << p.first << " : [";
        for(auto k: p.second){
            std::cout<< k.first << " " << k.second << "; ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}


///Question 3: Le vecteur de booléen Vu permet de marquer que le parcours est déjà passé par le sommet.
///Cette fonction ne suffit pas à elle seule car il faut lui fournir le vecteur Vu initialisé qu'avec des false.
void Liste::parcours_prof_rec_liste(std::string start, std::vector<bool>& Vu){
    Vu.at(sommets.dict[start]) = true; ///On marque le sommet actuel comme ayant été visité.
    std::cout << "sommet parcouru : " << start << std::endl;
    std::vector<bool> b (sommets.dict.size(), true);
    std::vector<Arete> y;
    Arete z;
    if(Vu == b){ ///Condition d'arrêt : tous les sommets ont été vus
        return;
    }
    else{
        y = voisins(start); /// Sinon on applique la fonction sur les voisins qui n'ont pas été vus précédemment.
        while(!(y.empty())){
            z = y.back();
            y.pop_back();
            if(!(Vu.at(sommets.dict[z.fils]))){
                z.print();
                parcours_prof_rec_liste(z.fils, Vu);
            }
        }
    }
}

void Liste::parcours_prof_rec_liste_final(std::string start){
    std::vector<bool> b (sommets.dict.size(),false);
    parcours_prof_rec_liste(start, b);
}



///Question 4: 
///Cette fonction parcourt la composante connexe du sommet nommé start et actualise la liste des sommets vus
std::vector<bool> Liste::parcours_prof_iter_liste(std::string start, std::vector<bool>& Vu){
    Arete a;
    std::vector<std::pair<std::string,Arete>> aVoir {std::make_pair(start,a)}; ///aVoir stocke les sommets qui doivent être traités
    /// ainsi que l'arête qui dans le parcours a permis d'accéder à ce sommet. aVoir est un vector mais il est utilisé comme une pile.
    Vu.at(sommets.dict[start]) = true;
    std::string x;
    std::vector<Arete> y;
    Arete z;
    while(!(aVoir.empty())){ /// La condition d'arrêt : il n'y a plus de sommets à traiter.
        x = aVoir.back().first;
        aVoir.back().second.print();
        std::cout << "sommet parcouru : " << x << std::endl;
        aVoir.pop_back();
        y = voisins(x);
        while(!(y.empty())){
            z = y.back();
            y.pop_back();
            if(!(Vu.at(sommets.dict[z.fils]))){
                aVoir.push_back(std::make_pair(z.fils,z));
                Vu.at(sommets.dict[z.fils]) = true;
            }
        }
    }
    return Vu;
}

///Fonction finale pour effectuer le parcours en profondeur
///On effectue un premier parcours sur la composante connexe du sommet d'origine.
///Ensuite on effectue autant de parcours que nécessaire jusqu'à ce que tous les sommets soient explorés.
void Liste::parcours_prof_iter_liste_final(std::string start){
    std::vector<bool> Vu (sommets.dict.size(),false);
    std::vector<bool> a  (sommets.dict.size(),true);
    int k {0};
    Vu = parcours_prof_iter_liste(start, Vu);
    while(Vu != a){
        while(Vu[k]){
            k = k + 1;
        }
        Vu = parcours_prof_iter_liste(sommets.dictbis[k], Vu);
    }
}



///Question 5 : On reprend le principe du parcours en profondeur en utilisant une structure de file plutôt qu'une structure de pile.
void Liste::parcours_large_iter_liste(std::string start, int i){
    Arete a;
    std::queue<std::pair<std::string,Arete>> aVoir;
    aVoir.push(std::make_pair(start,a));
    std::vector<bool> Vu (sommets.dict.size(),false);
    Vu.at(sommets.dict[start]) = true;
    std::string x;
    std::vector<Arete> y;
    Arete z;
    if (i!=0){
        i = i+1;
    }
    else{
        i = -1;
    }
    while(!(aVoir.empty())&&(i!=0)){
        if(x != aVoir.front().second.pere){
            i = i-1;
        }
        x = aVoir.front().first;
        aVoir.front().second.print();
        std::cout << "sommet parcouru : " << x << std::endl;
        aVoir.pop();
        y = voisins(x);
        while(!(y.empty())){
            z = y.back();
            y.pop_back();
            if(!(Vu.at(sommets.dict[z.fils]))){
                aVoir.push(std::make_pair(z.fils,z));
                Vu.at(sommets.dict[z.fils]) =true;
            }
        }
    }
}