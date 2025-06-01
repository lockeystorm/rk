#include <memory>
#include "maptile.h"

/* Virtual Proxy */
class MapTileProxy
{
public:
    MapTileProxy(double centerX, double centerY, double width, double height)
        : centerX_(centerX), centerY_(centerY), width_(width), height_(height)
    {}

    void Draw() const
    {
        if (realMapTile_ == nullptr)
        {
            realMapTile_ = std::make_unique<MapTile>(centerX_, centerY_, width_, height_);
        }
        realMapTile_->Draw();
    }

    double CenterX() const { return centerX_; }
    double CenterY() const { return centerY_; }
    double Width() const { return width_; }
    double Height() const { return height_; }

private:
    double centerX_, centerY_;
    double width_, height_;
    mutable std::unique_ptr<MapTile> realMapTile_;
};
