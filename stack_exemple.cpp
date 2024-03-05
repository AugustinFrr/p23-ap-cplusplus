 #include <iostream>

// merci à Gaspard Pereira pour ce code que j'étends

// Les membres des classes (attributs membres comme top ou fonctions membres comme push) on des visibilités
// i.e. ils peuvent être public ou private (et protected on y reviendra)
// public: tout le monde peut y accéder
// private: seules les fonctions membres de la structure de donnée peuvent y accéder

// struct ou class ?
// pour struct: par défaut les membres sont public
// pour class: par défaut les membres sont private
// il faut utiliser `class` pour éviter de mettre quelque chose en `public` et le regretter ensuite

class Stack
{
private:
    // les données qui composent ma structure de donnée
    // doivent rester privée à mon implémentation
    // je ne veut pas qu'une fonction autre que les fonctions membres de Stack puisse les modifier
    // je garde mon implémentation privée
    int nb;
    int size;
    char *tab;

public: // les fonctions qui permettent de manipuler les objets de type Stack seront public
    // tout d'abord les fonctions spécifiques de c++

    // le constructeur
    Stack(int m) : nb(0), size(m)
    {
        // j'effectue les vérifications nécessaires ici que la taille soit correcte
        if (size <= 0)
        {
            // la taille est incorrecte et je ne sais pas résoudre ce problème ici
            // je passe le problème à la fonction appelante grâce à throw
            // ici je throw un objet de type char* (un tableau de char)
            // on fera mieux
            throw "stop";
        }
        tab = new char[size];
    }

    // comme le constructeur réserve une ressource (ici un tableau de char alloué dans le tas par un new[])
    // je dois donner à la class la fonction pour libérer cette ressource
    // (où la zone allouée par new[] sera libérée par delete[])
    // cette fonction s'appelle le destructeur
    ~Stack()
    {
        delete[] tab;
    }

    // si je laisse c++ décider de la copie des objets de type Stack
    // il va faire une copie attribut à attribut (et copier les deux int et le char*)
    // mais il va recopier le pointeur et non pas dupliquer la zone mémoire allouée par new[]
    // les deux objets de type Stack vont avoir le même tab
    // i.e. donc pointer vers la même zone mémoire
    // par exemple
    // Stack s1(5);
    // Stack s2 = s1; // là une copie est faite
    // s1.push('a'); // on fait tab[0] = 'a'
    // s2.push('b')  // on fait tab[0] = 'b'
    // std::cout << s1.top();  va afficher 'b' !!!!!!

    // on va faire le constructeur de copie de manière à ce que les objets ne partagent pas tab

    // le constructeur de copie
    Stack(const Stack &rs) : nb(rs.nb), size(rs.size)
    {
        tab = new char[size];
        for (int i = 0; i < nb; i++)
        {
            tab[i] = rs.tab[i];
        }
    }

    // le même genre de problème apparaît avec l'opérateur d'affectation
    // par exemple
    // Stack s1(5);
    // Stack s2(3);
    // s1 = s2;
    // s1.push('a'); // on fait tab[0] = 'a'
    // s2.push('b')  // on fait tab[0] = 'b'
    // et en plus on a perdu en mémoire la zone allouée par new[] pour s1

    // ici pour gérer le problème je vais interdire l'affectation d'objets de type Stack
    void operator=(const Stack &rs) = delete;

    // EXERCICE 1: implémentez l'opérateur d'affectation pour mardi prochain

    // enfin les fonctions qui permettent de manipuler les piles empiler, dépiler etc.
    void push(char c)
    {
        if (isFull())
        {
            throw "stop";
        }
        tab[nb] = c;
        nb = nb + 1;
    }

    // je définis la méthode pop en dehors de la classe
    // voir plus bas
    char pop();

    // quand une méthode ne modifie pas l'objet sur lequel elle a été appelée
    // on la déclare comme const de manière à pouvoir l'appliquer sur les objets constants
    bool isEmpty() const
    {

        return nb == 0;
    }

    bool isFull() const
    {
        return nb == size;
    }

    void print() const
    {
        for (int i = 0; i < nb; i++)
        {
            std::cout << tab[i] << ' ';
        }
        std::cout << '\n';
    }

    char top()
    {
        if (isEmpty())
        {
            throw "stop";
        }
        return tab[nb - 1];
    }
};
// si je désire mettre l'implémentation d'une fonction membre
// en dehors de la définition de la structure de donnée Stack
// je fais de la manière suivante:
inline char Stack::pop()
{
    if (isEmpty())
    {
        throw "stop";
    }
    nb = nb - 1;
    return tab[nb];
}
// vous remarquez le inline on en parlera au prochain cours

// supposons que je n'ai pas de fonction top définie dans la structure de donnée
// je peux éventuellement en coder une de la manière suivante (merci à Gaspard)
inline char top_stack(Stack &rs)
{
    char c = rs.pop();
    rs.push(c);
    return c;
}

int main()
{
    Stack s1(3);
    s1.push('g');
    s1.push('a');
    s1.push('s');
    s1.print();

    std::cout << s1.top() << '\n';
    std::cout << top_stack(s1) << '\n';

    char c3 = s1.pop();
    char c2 = s1.pop();
    char c1 = s1.top();
    std::cout << c1 << c2 << c3 << '\n';

    std::cout << std::boolalpha << s1.isEmpty() << '\n';

    Stack s2(5);
    s2.push('a');

    // EXERCICE 2: décommentez la ligne suivante et essayez de comprendre ce qui se passe
    //  s1 = s2;
    //  ne pas oublier de remettre le commentaire après le test

    // maintenant je vais faire une exception
    Stack s3(2);

    // EXERCICE 3: décommentez la ligne suivante et essayez de comprendre ce qui se passe
    // s3.pop();
    // ne pas oublier de remettre le commentaire après le test

    // maintenant je vais faire une exception et la rattraper
    try
    {
        Stack s4(2);
        s4.pop();
    }
    // attention "stop" est un tableau de caractères constants
    // pour rattraper l'erreur je donne le type exact: const char*
    catch (const char *e)
    {
        std::cout << "exception rattrapée: " << e << '\n';
    }

    return 0;
}
// EXERCICE 4:
// - mettez la classe Stack dans un fichier stack.h
// - dans un fichier main.cpp, incluez stack.h et utilisez la

// EXERCICE 5:
// demander à voir en cours l'inclusion de plusieurs fois le même fichier stack.h