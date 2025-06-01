#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

struct Resource
{
    Resource() { std::cout << "* Load Resource. (Heavy Work) *" << std::endl; }
};

#endif
