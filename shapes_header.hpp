#include <iostream>
#include <vector>
#pragma once

//mon fichier


class Shape
{
protected: //de cette manière les classes dérivées auront accès à x, y et color
           //mais l'extérieur (main, autres fonctions et méthodes de classe) ne pourra pas y accéder
    int x;
    int y;
    int color;
    

public:
    Shape(int posx, int posy, int c=230) : x(posx), y(posy), color(c) {
        this->x = posx;
        this->y = posy;
        this->color = c;
    } // constructeur ; int c=230 définirait la valeur par défaut

    void move(int dx, int dy) // déplace l'objet
    {
        x = x + dx;
        y = y + dy;
    }
    virtual float area() const { return 99.999; } // !!!!! de toute façon je ne peux rien définir
                                    // mais il faut déclarer pour pouvoir en définir une dans les classes dérivées
};



class Circle : public Shape
{ // tous les objets de type Circle héritent des attributs de Shape
    int radius;

public:
    Circle(int posx, int posy, int r, int col) : radius(r), Shape(posx, posy, col) {} // constructeur
    float area() const { return 3.14 * radius * radius; }                                 // calcule l'aire du cercle
};



// Circle c; // c est un objet de type Circle
// // c.x = 3 ; ne marche pas car x est private
// // c.radius = 5 ; // marche car radius est public
// Circle *pc = &c;      // pc pointe vers c (x, y, color, radius)
// Shape *ps = &c;       // ps pointe vers c aussi mais il ne voit que x, y, color
// float a = ps->area(); // appelle la fonction area de Shape

