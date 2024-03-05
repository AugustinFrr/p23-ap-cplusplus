#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Sommet;

class Arete  //Edge
{
    friend class Graph;
    friend class Sommet;
protected :
    Sommet * target;
    double weight ;
    
public :
    Arete(Sommet * s, double w) : target(s), weight(w) {}

} ;


class Sommet // vertex
{
    friend class Arete;
    friend class Graph;
protected :
    int indice;
    std::vector<Arete> aretes ; //les deux sommets, départ et arrivée

public:
    Sommet() = default;
    Sommet(int i) : indice(i) {}
    void add_edge (int to, double value) {
        Sommet so=Sommet(to) ;
        aretes.at(to)=Arete(&so,value) ; }
    //bool est_adja (int j) {
    //    if (aretes[j].empty()) {
    //        return false ;
    //    } else {return false ;} ;
    //} ;
    
};

class Graph 
{
protected :
    // int length ; //nombre de sommets du graphe
    std::vector<Sommet> buffer ;

public :
    // Graph (int l, std::vector<Arete> vA) : length(l), buffer(vA) {}
    void add_vertex (int v) {
        buffer.push_back(Sommet(v));
    }

    void add_edge(int from, int to, double value) {
    //    buffer.at(from).aretes.push_back(Arete(&Sommet(to), value)) ;
    //on suppose que les indices sont ok, l'utilisateur ne propose que des choses qui marchent
    // vr: si tu regardes le code précédent tu verras que tu dois déléguer la création de l'arête à la classe Sommet
    //      dans le genre: 
        buffer.at(from).add_edge(to, value);
    
    }

} ;


// parcours en profondeur du graphe
// récursif


void parcours_profondeur (Graph g, int s, std::vector<bool> & visited) {
    visited[s]=true ;
    std::cout << s << std::endl ;
    for (int i=0 ; i<g.buffer.at(s).aretes.size() ; i++) {
        if (visited[g.buffer[s].aretes[i].target->indice]==false) {
            parcours_profondeur(g,g.buffer.at(s).aretes.at(i).target->indice,visited) ;
        } ;
    } ;
} ;

void parcours_profondeur (Graph g, int s) {
    std::vector<bool> visited(g.buffer.size(),false) ;
    parcours_profondeur(g,s,visited) ;
} ;

