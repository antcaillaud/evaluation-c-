#pragma once
#include <vector>
#include "arete.h"

///La fonction lire prend le nom d'un fichier texte représentant le graphe (il y a des règles de format à respecter)
///Le fichier texte doit dans sa première partie indiquer sur chaque ligne 
///le nom puis l'indice du sommet (si il y en a n, on indice de 0 à n-1).
///Ensuite on écrit "fin des sommets" sur une ligne lorsqu'on a finit de déclarer les sommets.
///Après cela on indique les arêtes ligne par ligne par le nom du sommet père, le nom du sommet fils, et enfin le poids.
std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> lire(std::string a);