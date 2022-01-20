#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "sommets.h"

std::map<std::string, int> dictionnaire_vide;

Sommets::Sommets():dict(dictionnaire_vide){}

Sommets::Sommets(std::map<std::string, int> dict, std::map<int,std::string> dictbis):dict(dict), dictbis(dictbis){}