#ifndef MAP_H
#define MAP_H

#include <vector>
#include <cassert>
#include "maptileproxy.h"

class Map
{
public:
    Map(double left, double top, double right, double bottom, std::size_t tileCountX, std::size_t tileCountY);

    void Print(bool draw) const;

private:
    std::vector<MapTileProxy> mapTileList_;
};

#endif
