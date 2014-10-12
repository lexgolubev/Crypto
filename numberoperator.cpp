#include "numberoperator.h"

NumberOperator::NumberOperator()
{
}

ullong NumberOperator::transpose(ullong text, const int* table, int length) {
    ullong result = 0;
    for (int i = 0; i < length; i++) {
        result = result << 1;
        result += getBitAt(text, table[i]);
    }
    return result;
}

ullong NumberOperator::transpose(uint text, const int* table, int length) {
    ullong result = 0;
    for (int i = 0; i < length; i++) {
        result = result << 1;
        result += getBitAt(text, table[i]);
    }
    return result;
}

uint NumberOperator::getBitAt(ullong text, int pos) {
    return 1 & (text >> (pos - 1));
}

uint NumberOperator::getBitAt(uint text, int pos) {
    return 1 & (text >> (pos - 1));
}

uint NumberOperator::left(ullong text) {
    return 0xffffffff & (text >> 32);
}

uint NumberOperator::right(ullong text) {
    return 0xffffffff & text;
}
