/*
  Utilisez cette classe Matrix pour faire un
  graphe sous la forme d'une matrice d'adjacence GraphMatrix ou
  modifiez la classe Matrix pour en faire une GraphMatrix.

  Faites un constructeur qui lit un graphe contenu dans un fichier
  (ci-dessous vous avez une fonction qui lit un fichier contenant un
  graphe).

  Implémentez l'algorithme ici:
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



void read_graph(const std::string &filename)
{
  // Cette fonction lit un graphe où:
  //   La première ligne du fichier filename contient le nombre de sommets.
  //   Les autres lignes contiennent les transitions entre les sommets du graphe.
  // Une transition est un triplet: from to value où
  //     où from est le numéro d'un sommet de départ
  //        to est le numéro d'un sommet d'arrivée
  //        value est la valeur (nombre réel) de la transition entre from et to.
  // from to value sont séparés par un espace

  // On ouvre le fichier en lecture.
  std::ifstream input_file(filename);

  // Si il y a eu un problème lors de l'ouverture du fichier:
  if (!input_file.is_open())
  {
    // On lance une exception.
    throw std::invalid_argument("Cannot open file " + filename);
  }

  // On va lire le fichier ligne par ligne en mettant chaque ligne dans une std::string.
  std::string line;

  // On lit la première ligne du fichier qui doit contenir le nombre de sommets du graphe.
  // Si il n'y a pas de lignes dans le fichier getline retourne false et on lance une exception.
  if (!getline(input_file, line))
  {
    throw std::invalid_argument("File " + filename + " is empty");
  }

  // La std::string line contient un entier.
  // On va transformer la string en un entier (fonction std::stoi string to integer)
  // et mettre l'entier dans la variable nb_vertices
  int nb_vertices = 0;
  // Là je considère que la traduction s'est bien passée.
  nb_vertices = std::stoi(line);

  // On lit toutes les lignes du fichier: quand il n'y en aura plus, getline retournera false.
  // On lit la ligne et on met son contenu dans la variable line.
  while (getline(input_file, line))
  {
    // Dans line, on sait qu'on a deux int et un double.
    // Pour extraire ces trois nombres, on construit un objet qui prend la string comme une entrée (istringstream).
    // Sur laquelle on va pouvoir lire avec, l'opérateur >>, nos 3 nombres.
    std::istringstream iss(line);
    int from, to;
    double value;
    iss >> from >> to >> value;
    // À cet endroit on affiche la transition.
    // On pourrait, à la place, la mettre dans un graphe.
    std::cout << "transition " << from << " -(" << value << ")-> " << to << std::endl;
  }
}

