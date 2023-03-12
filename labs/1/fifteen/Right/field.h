#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Field
{
private:
    size_t size = 4;
    vector<int> field;
    size_t zeroIndex = 0;
    inline Field(const Field& other);
    inline Field& operator = (const Field& other);

public:
    Field(size_t const& size = 4);
    ~Field();
    void generateStartField(size_t const& size = 4);
    size_t getSize() const;
    size_t getZeroIndex() const;
    vector<int> getField() const;
    void shiftUp();
    void shiftDown();
    void shiftLeft();
    void shiftRight();
    void shiftUp1();
    void shiftDown1();
    void shiftLeft1();
    void shiftRight1();
};