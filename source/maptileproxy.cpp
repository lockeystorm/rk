#include "maptileproxy.h"

MapTileProxy::MapTileProxy(double centerX, double centerY, double width, double height)
        : centerX_(centerX), centerY_(centerY), width_(width), height_(height) {}

void MapTileProxy::Draw() const
{
    if (realMapTile_ == nullptr)
    {
        realMapTile_ = std::make_unique<MapTile>(centerX_, centerY_, width_, height_);
    }
    realMapTile_->Draw();
}

double MapTileProxy::CenterX() const { return centerX_; }
double MapTileProxy::CenterY() const { return centerY_; }
double MapTileProxy::Width() const { return width_; }
double MapTileProxy::Height() const { return height_; }
