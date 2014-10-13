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

ullong Numbers::transpose(uiint text, const int* table, int length) {
    ullong result = 0;
    for (int i = 0; i < length; i++) {
        result = result << 1;
        result += getBitAt(text, table[i]);
    }
    return result;
}

uiint Numbers::getBitAt(ullong text, int pos) {
    return 1 & (text >> (pos - 1));
}

uint Numbers::getBitAt(uint text, int pos) {
    return 1 & (text >> (pos - 1));
}

uiint Numbers::left(ullong text) {
    return 0xffffffff & (text >> 32);
}

uiint Numbers::right(ullong text) {
    return 0xffffffff & text;
}

ullong Numbers::combine(ullong left, ullong right, int bit) {
    return (left << bit) + right;
}

uiint Numbers::combine(uiint left, uiint right, int bit) {
    return (left << bit) + right;
}
