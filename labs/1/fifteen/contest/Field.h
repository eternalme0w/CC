#pragma once
#include <iostream>
#include <vector>

class Field
{

    int size;
    std::vector<int> field;
    int zeroIndex;

    
    Field &operator=(Field);
    

public:

    Field(const Field&);

    bool operator==(Field);
    bool operator!=(Field);

    int num_cells;
    std::vector<int> good_field;

    Field(const int &size = 4);

    ~Field() = default;

    int getSize() const;
    std::vector<int> getField() const;
    int getZeroIndex() const;

    void generateStartField(int const &size = 4);

    void swap(int, int);

    void shiftRight();
    void shiftLeft();
    void shiftUp();
    void shiftDown();

    void out();
};