#include <vector>
#include <cassert>
#include "maptileproxy.h"

class Map
{
public:
    Map(double left, double top, double right, double bottom, std::size_t tileCountX, std::size_t tileCountY)
    {
        assert(tileCountX >= 1);
        assert(tileCountY >= 1);

        double width = (right - left) / tileCountX;
        double height = (bottom - top) / tileCountY;

        for (std::size_t i = 0; i < tileCountX; ++i)
        {
            for (std::size_t j = 0; j < tileCountY; ++j)
            {
                mapTileList_.emplace_back(width / 2 + width * i, height / 2 + height * j, width, height);
            }
        }
    }

    void Print(bool draw) const
    {
        for (auto const& mapTile : mapTileList_)
        {
            std::cout << "----- MapTile -----" << std::endl;
            std::cout << "Center Position       : (" << mapTile.CenterX() << ", " << mapTile.CenterY() << ")" << std::endl;
            std::cout << "Size (Width x Height) : " << mapTile.Width() << "x" << mapTile.Height() << std::endl;
            if (draw) mapTile.Draw();
            std::cout << "-------------------" << std::endl;
        }
    }

private:
    std::vector<MapTileProxy> mapTileList_;
};
