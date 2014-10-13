#ifndef NUMBEROPERATOR_H
#define NUMBEROPERATOR_H

#define ullong unsigned long long
#define uint unsigned int

class Numbers
{
private:
    Numbers();
public:
    static ullong transpose(ullong text, const int* table, int length);
    static ullong transpose(uint text, const int* table, int length);
    static uint getBitAt(ullong text, int pos);
    static uint getBitAt(uint text, int pos);
    static uint left(ullong text);
    static uint right(ullong text);
    static ullong combine(ullong left, ullong right, int bit);
    static uint combine(uint left, uint right, int bit);
};

#endif // NUMBEROPERATOR_H
