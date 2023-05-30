#pragma once


class Field {

    int size;
    int *field;
    int zeroIndex;

    Field(const Field&) = delete;
    Field& operator=(Field) = delete;

public:

    int num_cells;

    Field(const int& size = 4);
    
    ~Field();

    int getSize() const;
    int *getField() const;
    int getZeroIndex() const;

    void swap(int, int);

    void ShiftRight();
    void ShiftLeft();
    void ShiftUp();
    void ShiftDown();

    void generateStartField(int const& size = 4);

    void out();
};