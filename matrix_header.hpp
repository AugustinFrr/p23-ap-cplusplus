#include <iostream>
#include <stdexcept>
#include <vector>
/*

  1) Implémentez une classe Matrix avec le nombre de lignes (rows) et
  de colonnes (columns) de la matrice et avec un std::vector<float>
  pour contenir la matrice. La matrice est un seul vecteur pas un
  vecteur de vecteurs.

  Un premier constructeur crée une Matrix avec un nombre de lignes, de
  colonnes et une valeur pour tous les éléments de la matrice.

  Une méthode at(i, j) retourne l'élément à la position i, j de la
  matrice.

  Une méthode at(i, j, v) met la valeur v à la position (i, j) de la
  matrice.

  Une méthode print affiche la matrice (ligne par ligne).
*/ 

class Matrix {
protected :
  int rows;
  int columns;
  std::vector<float> buffer; // vr: utilise un nom différent pour le vecteur pour éviter les conflits de noms avec la classe Matrix
  // vr: mets une fonction qui calcule l'indice pour éviter de répéter le code
  // mets la en protected pour ne pas que l'extérieur puisse l'utiliser c'est ton implémentation interne
  // tu peux ici lancer une exception si l'utilisateur demande un indice en dehors des bornes
  int indice(int i, int j) const { return (i - 1) * columns + j - 1; }



public :
  // vr: tu peux mettre une valeur par défaut pour la valeur si elle n'est pas indiquée tu mets 0
  Matrix (int r, int c, float x) : rows(r), columns(c), buffer(r*c, x) {}
  // vr: si les bornes ne sont pas bonnes buffer[] lancera une exception
  // ce n'est peut être pas l'exception qui te convient puisqu'elle ne parlera pas de lignes et de colonnes
  // mais d'un problème d'indice entre 0 et rows*columns-1
  // d'où l'intérêt de lancer l'exception dans la fonction indice

  float at (int i, int j) const { return buffer[(i-1)*columns + j-1]; }

  //on suppose que l'utilisateur appelle (1,1) l'élément (0,0) de l'ordinateur

  void at (int i, int j, float v) {buffer[(i-1)*columns + j-1] = v; }
  
  void print () const {
    for (int i=1 ; i<=rows ; i++) {
      for (int j=1 ; j<=columns ; j++) {
            std::cout<<at(i,j)<<" " ; }
      std::cout<<std::endl ; }
  }
} ;

