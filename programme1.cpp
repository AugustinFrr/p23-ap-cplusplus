#include <iostream>
/*
const int i ;

int main () {
    {int i ;
    // i ici est différent du i global au dessus
    // i ici est une variable locale
    }
    //le i local ci dessus n'existe plus
    int i ;
    int * pi = new int;
    // pi est un pointeur vers un int
    // dans la pile (stack) pi est au-dessus de i 
    // pi pointe vers une place du heap
    // si je mets ces 2 lignes entre { }, on sort i et pi de la pile
    // cela fait une memory leak/fuite mémoire
    // c'est pas cool
    // pour détruire on utilise delete pi;
    //si j'avais écrit int i[4] ; ça m'aurait créé un tableau i de 4 int
 
}

SE RENSEIGNER SUR DANDLING LEAK (adresse mal initialisée)
*/

void swap (int * x, int * y) {
    int c=*x;
    *x=*y;
    *y=c;
}

int main() {
    int a=17;
    int b=82;
    swap (&a,&b);
    bool bol=((a==82) and (b==17));
    std::cout << bol << std::endl;
    }



