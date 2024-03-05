#include <vector>
#include <iostream>
#include "shapes.hpp"
#include "rectangle.hpp"

int main()
{
    Circle c(10, 20, 3, 450);
    std::cout << c.area() << std::endl;
    Circle *pc = &c;
    std::cout << pc->area() << std::endl;
    Shape *ps = &c;
    std::cout << ps->area() << std::endl;

    // voir question 2 et 3 du devoir
    rectangle r(10, 20, 300, 500, 450);
    std::cout << r.area() << std::endl;
    rectangle *pr = &r;
    std::cout << pr->area() << std::endl;
    Shape *psr = &r;
    std::cout << psr->area() << std::endl;
    return 0;
    
}
/* les devoirs pour le 9/01/2024:

1) lisez, comprenez, compilez le code shape.hpp et main_shape.cpp et posez moi vos questions

2) faites un fichier rectangle.hpp qui inclut le fichier shape.hpp
   et définit la classe des Rectangle
   vous ne devez pas modifier le fichier shape.hpp
   (vous ne devez pas définir la classe Rectangle dans shape.hpp)

3) dans le fichier main.cpp testez votre classe rectangle
   (comme on a testé le Circle)

4) envoyez moi vos devoirs avant le prochain cours du 9 janvier

5) si vous avez des problèmes envoyez moi votre code que je le corrige
*/