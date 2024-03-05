
#include <iostream>
#include <stdexcept>
#include "matrix.hpp"
int main()
{
    try
    {

        Matrix m(-4, 3, 1.);
        std::cout << m.at(2, 2) << std::endl;
        m.at(2, 2, 2.);
        m.print();
        std::cout << m.at(2, 2) << std::endl;

        m.at(5, 2, 2.);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}