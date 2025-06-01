#ifndef MAPTILEPROXY_H
#define MAPTILEPROXY_H

#include <memory>
#include "maptile.h"

/* Virtual Proxy */
class MapTileProxy
{
public:
    MapTileProxy(double centerX, double centerY, double width, double height);

    void Draw() const;

    double CenterX() const;
    double CenterY() const;
    double Width() const;
    double Height() const;

private:
    double centerX_, centerY_;
    double width_, height_;
    mutable std::unique_ptr<MapTile> realMapTile_;
};

#endif
