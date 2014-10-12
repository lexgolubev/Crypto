#include "numbers.h"

Numbers::Numbers()
{
}

ullong Numbers::transpose(ullong text, const int* table, int length) {
    ullong result = 0;
    for (int i = 0; i < length; i++) {
        result = result << 1;
        result += getBitAt(text, table[i]);
    }
    return result;
}

ullong Numbers::transpose(uint text, const int* table, int length) {
    ullong result = 0;
    for (int i = 0; i < length; i++) {
        result = result << 1;
        result += getBitAt(text, table[i]);
    }
    return result;
}

uint Numbers::getBitAt(ullong text, int pos) {
    return 1 & (text >> (pos - 1));
}

uint Numbers::getBitAt(uint text, int pos) {
    return 1 & (text >> (pos - 1));
}

uint Numbers::left(ullong text) {
    return 0xffffffff & (text >> 32);
}

uint Numbers::right(ullong text) {
    return 0xffffffff & text;
}
