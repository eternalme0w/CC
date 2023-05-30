#include "Field.h"


Field::Field(const int &size)
{
    
    generateStartField(size);
}

Field::Field(const Field& f) {

    size = f.size;
    field = f.field;
    zeroIndex = f.zeroIndex;
}

void Field::generateStartField(const int &size)
{

    field.clear();
    
    this->size = size;
    num_cells = size * size;

    for (int i = 1; i <= num_cells; ++i)
        field.push_back(i);

    zeroIndex = num_cells - 1;
    field[zeroIndex] = 0;

    good_field = getField();
}


int Field::getSize() const
{

    return size;
}

std::vector<int> Field::getField() const
{   
    return field;
}

int Field::getZeroIndex() const
{

    return zeroIndex;
}

void Field::swap(int i1, int i2)
{

    int tmp = field[i1];
    field[i1] = field[i2];
    field[i2] = tmp;
}

void Field::shiftRight()
{

    if ((zeroIndex + 1) % size)
    {

        swap(zeroIndex, zeroIndex + 1);
        zeroIndex++;
    }
}

void Field::shiftLeft()
{

    if (zeroIndex % size)
    {

        swap(zeroIndex, zeroIndex - 1);
        zeroIndex--;
    }
}

void Field::shiftUp()
{

    if ((zeroIndex - size) >= 0)
    {

        swap(zeroIndex, zeroIndex - size);
        zeroIndex -= size;
    }
}

void Field::shiftDown()
{

    if ((zeroIndex + size) < num_cells)
    {

        swap(zeroIndex, zeroIndex + size);
        zeroIndex += size;
    }
}

void Field::out()
{

    printf("\n\n\n\n\n\n\n\n");

    printf("                                 ");

    for (int i = 1; i <= num_cells; ++i)
    {

        if (i % size != 0)
            printf("  %-4d", field[i - 1]);

        else
        {

            printf("  %-4d\n\n", field[i - 1]);
            printf("                                 ");
        }
    }
}

bool Field::operator==(Field f) {

    return field == f.field;
}

bool Field::operator!=(Field f) {

    return field != f.field;
}
