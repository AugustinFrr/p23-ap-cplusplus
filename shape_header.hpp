#pragma once
#include <iostream>
//fichier du prof


// classe qui servira de base à des classes plus spécifiques comme Circle ou Rectangle
class Shape
{
    // protected afin que les classes dérivées de Shape puissent accéder à x, y et color
    // sans que l'extérieur (main, autres fonctions et méthodes de classe) puisse y accéder
protected:
    int x;
    int y;
    int color;

// il faut que Shape soit public et non protected: le type Shape servira dans des fonctions extérieures à la classe
// comme par exemple dans le main
public:
    Shape(int x, int y, int color = 230) // par défaut (si vous ne le donnez pas lors de l'appel) color est à 230
    // les trois attributs de la classe Shape sont cic initialisés dans la liste d'initialisation
        : x(x), y(y), color(color) {
            // vous remarquez que j'ai donné le même nom aux attributs et aux arguments de la méthode de construction
            // c'est pour vous montrer comment leur affecter une valeur
            // ici on serait obligé d'utiliser this pour indiquer quel est le x, y et color celui de this ou celui des arguments
            this->x = x; // donc inutile puisque x, y et color sont déjà initialisés: c'est pour l'exemple !!!
            this->y = y;
            this->color = color;
           // pour éviter les problèmes prenez des noms d'arguments différents 
        }

public:
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }

    // la méthode area n'a pas de signification pour un objet de type Shape
    // son seul intérêt ici est d'être déclarée pour pouvoir l'appeler sur un pointeur Shape* ou une référence Shape&
    // sachant que l'objet référé sera un objet d'un type dérivé
    // comme dans:
    // Circle c(10, 20, 4);
    // std::cout << c.area();
    // Shape* ps = &c;
    // std::cout << ps->area();
    // const puisque la méthode ne modifie pas l'objet sur lequel elle est appelée
    // =0 puisque je ne peux pas donner une définition satisfaisante de la méthode
    virtual float area() const = 0;

    // une classe qui contient une fonction =0 devient une classe abstraite:
    //  - on ne pourra plus créer un objet du type exact de celle classe genre
    // Shape s(10, 20, 245);
    // puisque c++ ne saura plus faire:
    // s.area();
};



// la classe Circle hérite de la classe Shape
// un Circle est une Shape avec des choses en plus
// les méthodes en plus (comme ici area) doivent être définies dans la classe mère
// quand vous allez les appeler sur les pointeurs ou des références de type Shape
class Circle : public Shape
{
    int radius;

public:
    Circle(int x, int y, int radius, int color = 250) // par défaut color des Circle est à 250
        : Shape(x, y, color), // on appelle le constructeur de la classe de base Shape en lui passant les arguments
          radius(radius)

    {
    }

    float area() const { return 3.14 * radius * radius; }
};


