#include <vector>
#include <iostream>

#include "Figure.h"

class Board {


public:

    std::vector<std::vector<int>> board;
    int size;

    Board(const int&);
    void setQueen(int, int);
    void removeQueen(int, int);

    void problem_1(int);
    void problem_2(int, int);

    void out();


};
