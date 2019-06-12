#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "busca.h"

//bibliiotecas usadas em outrostestes
#include <algorithm>
#include <iostream>
#include <limits>
#include <cmath>

//bibliotecas usadas em busca.cpp
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <list>
#include <math.h>
#include "indice.h"

using std::string;
using std::map;
using std::list;
using std::vector;

class Teste{
    public:
        static string expBusca(const Busca& q){
            return q.exp_;
        }
        static vector<string> vetExp(const Busca& q){
            return q.vetExp_;
        }
        static map<double, string> ordemDocumentos(const Busca& q){
            return q.ordemDocumentos_;
        }
};