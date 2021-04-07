#pragma ONCE
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <tuple>
#include <map>

namespace ariel
{
    class Board
    {
        std::map<std::pair<u_int, u_int>, char> board;
        char read_map(u_int x, u_int y);
    public:
        std::string read(u_int row, u_int column, Direction direction, u_int length);
        void post(u_int row, u_int column, Direction direction, std::string message);
        void show();
    };
}