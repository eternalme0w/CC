#include "Board.h"

Board::Board(const int &size) : size(size) {

    std::vector<int> tmp;

    for (int i = 0; i < size; i++) {

        tmp.clear();

        for (int j = 0; j < size; j++) 
            tmp.push_back(0);
        
        board.push_back(tmp);
    }
}

void Board::problem_1(int i) {

    for (int j = 0; j < size; j++) {

        if (board[i][j] == 0) {

            setQueen(i, j);

            if (i == size - 1) out();
            else {

                problem_1(i + 1);
            } 

            removeQueen(i, j);

        }
    }
}

void Board::problem_2(int i, int queens_left) {

    if (queens_left == 0) return;


}



void Board::setQueen(int i, int j) {

    int d1 = i + j;
    int d2 = i - j;

    for (int x = 0; x < size; x++) {

        board[x][j] += 1;
        board[i][x] += 1;

        if (d1 - x >= 0 && d1 - x < size) board[d1 - x][x] += 1;
        if (d2 + x >= 0 && d2 + x < size) board[d2 + x][x] += 1;

        board[i][j] = -1;
    }
}

void Board::removeQueen(int i, int j) {

    if (board[i][j] != -1) return;

    int d1 = i + j;
    int d2 = i - j;

    for (int x = 0; x < size; x++) {

        board[x][j] -= 1;
        board[i][x] -= 1;

        if (d1 - x >= 0 && d1 - x < size) board[d1 - x][x] -= 1;
        if (d2 + x >= 0 && d2 + x < size) board[d2 + x][x] -= 1;

        board[i][j] = 0;
    }
}

void Board::out() {

    std::cout << "\n";
    std::string space = "  ";
    bool f;
    int j = 0;

    std::cout << "   ";
    for (int i = 0; i < size; i++) printf("%2d  ", i);
    std::cout << "\n\n";

    for (auto s : board) {

        f = false;

        for (auto x : s) {

            if (!f) std::cout << j++ << "| ";
            //std::cout << x << space;
            printf("%2d  ", x);
            f = true;
        }
         std::cout << "\n\n";
    }
}