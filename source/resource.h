#include <iostream>

struct Resource
{
    Resource() { std::cout << "* Load Resource. (Heavy Work) *" << std::endl; }
};
