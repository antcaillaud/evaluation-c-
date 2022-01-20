#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "liste.h"
#include "lire.h"



///Cette fonction teste si les implémentations de classe ont bien été éffectuées.
///On va tester les constructeurs, les fonctions pour passer d'une représentation à une autre, et les fonctions d'affichage.
void test_question_1(std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res, Sommets a){
    std::cout << "Tests Question 1 :" << std::endl;
    Liste graph_list {res.second, a};
    Matrice graph_mat {res.second, a};
    Matrice graph_mat_bis = graph_list.Liste_to_Matrice();
    Liste graph_list_bis = graph_mat.Matrice_to_Liste();
    std::cout << "Arêtes partant de a :" << std::endl;
    graph_list.print_voisins("a"); ///Cette fonction permet de vérifier que les fonctions pour accéder aux arêtes d'un sommet fonctionnent
    std::cout << "Affichage de la représentation par listes d'adjacence :" << std::endl;
    graph_list.print();
    std::cout << "Pour vérifier que la fonction Matrice_to_Liste fonctionne correctement (les listes d'adjacence doivent être identiques) :" << std::endl;
    graph_list_bis.print();
    std::cout << "Affichage de la représentation par matrice d'adjacence :" << std::endl;
    graph_mat.print();
    std::cout << "Pour vérifier que la fonction Liste_to_Matrice fonctionne correctement (la matrice d'adjacence doit être identique) :" << std::endl;
    graph_mat_bis.print();
}

///On va tester les parcours en profondeur récursifs avec les deux représentations
void test_question_3(std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res, Sommets a){
    std::cout << "Tests Question 3 :" << std::endl;
    Liste graph_list {res.second, a};
    Matrice graph_mat {res.second, a};
    std::cout << "Parcours en profondeur récursif avec les listes d'adjacence :" << std::endl;
    graph_list.parcours_prof_rec_liste_final("a");
    std::cout << "Parcours en profondeur récursif avec la matrice d'adjacence :" << std::endl;
    graph_mat.parcours_prof_rec_matrice_final(0); 
    ///0 représente le sommet a dans la représentation matricielle. On devrait donc obtenir le même résultat dans les 2 parcours.
}

///On teste cette fois-ci les parcours en profondeur itératifs.
void test_question_4(std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res, Sommets a){
    std::cout << std::endl << "Tests Question 4 :" << std::endl;
    Liste graph_list {res.second, a};
    Matrice graph_mat {res.second, a};
    std::cout << "Parcours en profondeur itératif avec les listes d'adjacence :" << std::endl;
    graph_list.parcours_prof_iter_liste_final("a");
    std::cout << "Parcours en profondeur itératif avec la matrice d'adjacence :" << std::endl;
    graph_mat.parcours_prof_iter_matrice_final(0);
}

///On teste les parcours en largeur. Ceux-ci sont codés de manière itérative.
void test_question_5(std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res, Sommets a){
    std::cout << std::endl << "Tests Question 5 :" << std::endl;
    Liste graph_list {res.second, a};
    Matrice graph_mat {res.second, a};
    std::cout << "Parcours en largeur complet avec les listes d'adjacence :" << std::endl;
    graph_list.parcours_large_iter_liste("a",0);
    std::cout << "Parcours en largeur complet avec la matrice d'adjacence :" << std::endl;
    graph_mat.parcours_large_iter_matrice(0,0);
    std::cout << "Parcours en largeur de niveau 1 avec les listes d'adjacence :" << std::endl;
    graph_list.parcours_large_iter_liste("a",1);
}

void test_question_7(std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res, Sommets a){
    std::cout << std::endl << "Tests Question 7 :" << std::endl;
    Matrice graph_mat {res.second, a};
    std::pair<Matrice,std::vector<std::vector<std::vector<Arete>>>> s = graph_mat.Floyd_Warshall();
    std::cout << "Matrice indiquant les poids des plus cours chemins du sommet d'indice i au sommet d'indice j :" << std::endl;
    s.first.print();
    std::cout << "Plus court chemin de a à e:" << std::endl;
    for (auto k : s.second.at(0).at(4)){
        k.print();
    }
}

int main(int argc, char** argv){
    ///On lit le fichier en argument de l'éxécutable et on récupère un triplet composé de deux dictionnaires permettant de faire
    /// la correspondance entre les noms et les indices des sommets ainsi que d'un vecteur contenant toutes les arêtes du graphe.
    if (argc == 1){
        std::cout << "pas de fichier indiqué en entrée" << std::endl;
        return 0;
    }
    
    
    else if (argc == 2){
        std::pair<std::pair<std::map<std::string, int>,std::map<int,std::string>>,std::vector<Arete>> res = lire(std::string(argv[1]));
        Sommets a {res.first.first,res.first.second};
        test_question_1(res, a);
        test_question_3(res, a);
        test_question_4(res, a);
        test_question_5(res, a);
        test_question_7(res, a);
        return 0;
    }
    else{
        std::cout << "trop d'arguments" << std::endl;
        return 0;
    }
}