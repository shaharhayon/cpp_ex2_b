#include "Board.hpp"
#include <climits>

using namespace std;
using namespace ariel;

char Board::read_map(u_int x, u_int y)
{
    auto ptr = board.find(pair<u_int, u_int>(x, y));
    if (ptr == board.end())
    {
        return '_';
    }
    return ptr->second;
};

string Board::read(u_int row, u_int column, Direction direction, u_int length)
{
    string ans;
    switch (direction)
    {
    case Direction::Horizontal:
    {
        for (u_int i = 0; i < length; i++)
        {
            ans.push_back(read_map(column + i, row));
        }
    }
    break;
    case Direction::Vertical:
    {
        for (u_int i = 0; i < length; i++)
        {
            ans.push_back(read_map(column, row + i));
        }
    }
    break;
    }
    return ans;
};
void Board::post(u_int row, u_int column, Direction direction, std::string message)
{
    switch (direction)
    {
    case Direction::Horizontal:
    {
        for (u_int i = 0; i < message.length(); i++)
        {
            board[pair<u_int, u_int>(column + i, row)] = message.at(i);
        }
    }
    break;
    case Direction::Vertical:
    {
        for (u_int i = 0; i < message.length(); i++)
        {
            board[pair<u_int, u_int>(column, row + i)] = message.at(i);
        }
    }
    break;
    }
};
void Board::show()
{
    u_int end_x = 0;
    u_int end_y = 0;
    u_int start_x = UINT_MAX; 
    u_int start_y = UINT_MAX;
    // std::map<pair<u_int, u_int>, char>::iterator iter = board.begin();
    for(auto element : board) // element is of type: pair<pair<u_int, u_int>, char>
    {
        if (element.first.first < start_x)
        {
            start_x = element.first.first;
        }
        if (element.first.first > end_x)
        {
            end_x = element.first.first;
        }
        if (element.first.second < start_y)
        {
            start_y = element.first.second;
        }
        if (element.first.second > end_y)
        {
            end_y = element.first.second;
        }
    }

    for (u_int y = start_y; y <= end_y; y++)
    {
        for (u_int x = start_x; x <= end_x; x++)
        {
            cout << read_map(x, y) << ends;
        }
        cout << endl;
    }
};