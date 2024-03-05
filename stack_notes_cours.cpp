#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

#pragma once

// int main () {
//     int m=3 ;
//     int * tabl = create_tab(m);
// }

// tout ça va poser pb car la variable tabl est détruite à la fin de la fonction create_tabbbbb
// il faut donc allouer dynamiquement la mémoire :
// int * create_tab(int n) {
//     int * t = new int[n];
//     return t;
// }


class Stack {
private :
    //données de construction de la stack (initialisation de structure)
    int nb ;
    int size ;
    char * tab ; 

public :
    //méthodes
    Stack (int n) : nb(0), size(n) { //CONSTRUCTEUR
        tab = new char [n] ; // "tab=new char[size]" impossible" car dans mon initialisation de structure
        } ;                  // size est défini *après* tab
    ~Stack () {                      //DESTRUCTEUR
        delete [] tab ;
        }  
    void push(char c) {  //empile un élémt sur ma pile
        if (nb == size) {
            throw "stop" ; } 
        else {
            tab[nb] = c;
            nb++; }
        }
    bool is_empty() { //vérifie si ma pile est vide
        return (nb == 0);
        }
    bool is_full() { //vérifie si ma pile est pleine
        return (nb == size);
        }
    char pop() {  //dépile un élément de ma pile
        if (is_empty()) {
            throw "stop" ; }
        else {
            nb--;
            return tab[nb]; }
        }
    void print() { //affiche la pile
        for (int i =0 ; i<nb ; i++) {
            std::cout<<tab[i]<<std::endl; }
        }
    char top() {  //affiche le sommet de la pile
        if (is_empty()) {
            throw "stop" ; }
        else {
            return tab[nb-1];  }  //on pourrait utiliser (*this).tab ou this->tab
        }
    //constructeur de copie
    Stack (const Stack & rs) : nb(rs.nb), size(rs.size) {
        tab = new char [size] ;
        for (int i=0 ; i<nb ; i++) {
            tab[i] = rs.tab[i] ; }
        }
    void operator=(const Stack & rs) {
        nb = rs.nb ;
        size = rs.size ;
        delete [] tab ;
        tab = new char [size] ;
        for (int i=0 ; i<nb ; i++) {
            tab[i] = rs.tab[i] ; }
        }
    } ;

int main() {
    Stack s1=12;
    Stack s2=s1 ; // construit un nouvel objet s2 en regardant dans ma classe si j'ai fait un constructeur de copie : ce n'est pas 
                  // le cas donc il le fait tout seul en copiant les int, char qu'il connait
                  // mais du coup le pointeur est le même donc chiant
                  // parce que si mon stack s2=s1 était entre {} à la fin il fait le destructeur 
                  // et donc le pointeur de s1 ne pointe plus vers rien -> c'est mortttt
                  // (si je mets &s2=s1, s2 est une seule case mémoire qui pointe vers tout s1) 
    } ;

operator<<(std::ostream& os, const int, Stack&s) {
s.print(os);
} ;
