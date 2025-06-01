#ifndef MAPTILE_H
#define MAPTILE_H

#include "resource.h"

class MapTile
{
public:
    MapTile(double centerX, double centerY, double width, double height);

    void Draw() const;

    double CenterX() const;
    double CenterY() const;
    double Width() const;
    double Height() const;

private:
    double centerX_, centerY_;
    double width_, height_;
    Resource resource_;
};

#endif
