#ifndef NUMBEROPERATOR_H
#define NUMBEROPERATOR_H

#define ullong unsigned long long
#define uint unsigned int

class NumberOperator
{
private:
    NumberOperator();
public:
    static ullong transpose(ullong text, const int* table, int length);
    static ullong transpose(uint text, const int* table, int length);
    static uint getBitAt(ullong text, int pos);
    static uint getBitAt(uint text, int pos);
    static uint left(ullong text);
    static uint right(ullong text);
};

#endif // NUMBEROPERATOR_H
