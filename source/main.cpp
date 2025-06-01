#include "resource.h"
#include "maptile.h"
#include "maptileproxy.h"
#include "map.h"

int main()
{
    Map map(0, 0, 60, 90, 2, 2);

    map.Print(false);
    std::cout << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
    map.Print(true);
    std::cout << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
    map.Print(true);
}
