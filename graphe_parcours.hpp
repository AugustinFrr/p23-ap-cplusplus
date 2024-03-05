// parcours en profondeur du graphe
// récursif

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include "graph.hpp"


void parcours_profondeur (Graph g, int s, std::vector<bool> & visited) {
    visited[s]=true ;
    std::cout << s << std::endl ;
    for (int i=0 ; i<g.buffer.at(s).aretes.size() ; i++) {
        if (visited[g.buffer.at(s).aretes.at(i).target->indice]==false) {
            parcours_profondeur(g,g.buffer.at(s).aretes.at(i).target->indice,visited) ;
        } ;
    } ;
} ;

void parcours_profondeur (Graph g, int s) {
    std::vector<bool> visited(g.buffer.size(),false) ;
    parcours_profondeur(g,s,visited) ;
} ;



