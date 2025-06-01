#include "resource.h"

class MapTile
{
public:
    MapTile(double centerX, double centerY, double width, double height)
        : centerX_(centerX), centerY_(centerY), width_(width), height_(height)
    {
        // Load resource. (Heavy Work)
    }

    void Draw() const
    {
        std::cout << "* Draw MapTile from resouce. *" << std::endl;
    }

    double CenterX() const { return centerX_; }
    double CenterY() const { return centerY_; }
    double Width() const { return width_; }
    double Height() const { return height_; }

private:
    double centerX_, centerY_;
    double width_, height_;
    Resource resource_;
};
