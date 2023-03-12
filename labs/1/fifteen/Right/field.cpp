#include "Field.h"
#include <vector>
#include <conio.h>
#include <iostream>

using namespace std;

int cnt = 0;


Field::Field(size_t const& size)
{
    this->generateStartField(size);
}
Field::~Field()
{
    field.clear();
}
Field::Field(const Field& other)
{
}
Field& Field::operator=(const Field& other)
{
    return *this;
}
void Field::generateStartField(size_t const& size)
{
    zeroIndex = size * size - 1;

    this->size = size;
    field.clear();

    for (int i = 0; i < (size * size) - 1; i++)
    {
        field.push_back(i + 1);
    }
    field.push_back(0);
}
size_t Field::getSize() const
{
    return size;
}
size_t Field::getZeroIndex() const
{
    return zeroIndex;
}
std::vector<int> Field::getField() const
{
    return field;
}
void Field::shiftUp()
{
    if (zeroIndex >= size)
    {
        cnt++;
        swap(field[zeroIndex - size], field[zeroIndex]);
        zeroIndex -= size;
        cout << cnt;
    }
    else cout << cnt;
}
void Field::shiftDown()
{
    if (zeroIndex + size < size * size)
    {
        cnt++;
        swap(field[zeroIndex], field[zeroIndex + size]);
        zeroIndex += size;
        cout << cnt;
    }
    else cout << cnt;

}
void Field::shiftLeft()
{
    if (zeroIndex % size != 0) 
    {
        cnt++;
        swap(field[zeroIndex - 1], field[zeroIndex]);
        zeroIndex -= 1;
        cout << cnt;
    }
    else cout << cnt;
}
void Field::shiftRight()
{
    if (zeroIndex % size != size - 1)
    {
        cnt++;
        swap(field[zeroIndex], field[zeroIndex + 1]);
        zeroIndex += 1;
        cout << cnt;
    }
    else cout << cnt;
}

void Field::shiftUp1()
{
    if (zeroIndex >= size)
    {
        swap(field[zeroIndex - size], field[zeroIndex]);
        zeroIndex -= size;
    }
  
}
void Field::shiftDown1()
{
    if (zeroIndex + size < size * size)
    {
        swap(field[zeroIndex], field[zeroIndex + size]);
        zeroIndex += size;
    }


}
void Field::shiftLeft1()
{
    if (zeroIndex % size != 0)
    {
        swap(field[zeroIndex - 1], field[zeroIndex]);
        zeroIndex -= 1;
    }
}

void Field::shiftRight1()
{
    if (zeroIndex % size != size - 1)
    {
        swap(field[zeroIndex], field[zeroIndex + 1]);
        zeroIndex += 1;
    }
}