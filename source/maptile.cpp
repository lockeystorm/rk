#include "maptile.h"

MapTile::MapTile(double centerX, double centerY, double width, double height)
        : centerX_(centerX), centerY_(centerY), width_(width), height_(height)
{
        // Load resource. (Heavy Work)
}

void MapTile::Draw() const {
        std::cout << "* Draw MapTile from resouce. *" << std::endl;
}

double MapTile::CenterX() const { return centerX_; }
double MapTile::CenterY() const { return centerY_; }
double MapTile::Width() const { return width_; }
double MapTile::Height() const { return height_; }

