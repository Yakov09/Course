#ifndef CHESSFIELD_H
#define CHESSFIELD_H


class Chessfield
{
    int number;
    bool empty;
    int color;  // 0 - white, 1 - black, more for other design
public:
    Chessfield(int num, bool em, int col);
    bool isEmpty();
    void setEmpty(bool status);
    int getColor();
    void setColor(int color);
    int getNumber();
    void setNumber(int num);
};

#endif // CHESSFIELD_H
