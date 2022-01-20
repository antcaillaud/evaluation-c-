#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "arete.h"
#include "lire.h"


std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> lire(std::string a){
    std::string const nomFichier(a);
    std::ifstream flux(nomFichier.c_str());
    std::string ligne;
    std::string nom;
    int indice;
    std::string pere;
    std::string fils;
    float poids;
    std::map<std::string, int> dict;
    std::map<int,std::string> dictbis;
    std::vector<Arete> res;
    if (flux){
        ///on lit d'abord la première partie du fichier pour créer les sommets et les associations nom et indice de chacun.
        while(getline(flux, ligne) && (ligne!="fin des sommets")){
            flux.seekg(-ligne.size()-1, std::ios::cur);
            flux >> nom;
            flux >> indice;
            flux.seekg(+1, std::ios::cur);
            dict[nom] = indice;
            dictbis[indice] = nom;
        }
        while(getline(flux, ligne)){
            flux.seekg(-ligne.size()-1, std::ios::cur);
            flux >> pere;
            flux >> fils;
            flux >> poids;
            flux.seekg(+1, std::ios::cur);
            Arete a {pere, fils, poids};
            res.push_back(a);
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    return std::make_pair(std::make_pair(dict,dictbis), res);
}

