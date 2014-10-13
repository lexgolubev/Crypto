#include "des.h"

Des::Des()
{
}

ullong Des::encrypt(ullong text, ullong key) {
    DesRoundKeyGenerator generator(key);
    ullong newText = Numbers::transpose(text, INIT_TRANSPOSE_TABLE, 64);
    uiint a = Numbers::left(newText);
    uiint b = Numbers::right(newText);
    for (int i = 1; i < 16; i++) {
        uiint temp = b;
        b = a ^ f(b, generator.getKey(i));
        a = temp;
    }
    a ^= f(b, generator.getKey(16));
    ullong result = Numbers::combine((ullong)a, (ullong)b, 32);
    return Numbers::transpose(result, FINAL_TRANSPOSE_TABLE, 64);
}

ullong Des::decrypt(ullong text, ullong key) {
    DesRoundKeyGenerator generator(key);
    ullong newText = Numbers::transpose(text, INIT_TRANSPOSE_TABLE, 64);
    uiint a = Numbers::left(newText);
    uiint b = Numbers::right(newText);
    for (int i = 1; i < 16; i++) {
        uiint temp = b;
        b = a ^ f(b, generator.getKey(16 - i));
        a = temp;
    }
    a ^= f(b, generator.getKey(1));
    ullong result = Numbers::combine((ullong)a, (ullong)b, 32);
    return Numbers::transpose(result, FINAL_TRANSPOSE_TABLE, 64);
}

ullong Des::f(uiint text, ullong key) {
    ullong extendedText = Numbers::transpose(text, EXTEND_TEXT_TABLE, 48);
    extendedText ^= key;
    uiint result = 0;
    for (int i = 0; i < 8; i++) {
        uiint block = extendedText & 0x3f;
        int raw = block >> 4;
        int column = block & 0xf;
        result = Numbers::combine(result, S[i][raw][column], 4);
        extendedText >>= 6;
    }
    return Numbers::transpose(result, TRANSPOSE_FRAGMENTS_TABLE, 32);
}
