#include "des.h"

Des::Des(ullong key) : key(key)
{
    generator = new DesRoundKeyGenerator(key);
}

ullong Des::encrypt(ullong text) {
    ullong newText = NumberOperator::transpose(text, INIT_TRANSPOSE_TABLE, 64);
    uint a = NumberOperator::left(newText);
    uint b = NumberOperator::right(newText);
    for (int i = 0; i < 15; i++) {
        uint temp = b;
        b = a ^ f(b, generator->getKey(i));
        a = temp;
    }
    a ^= f(b, generator->getKey(15));
    ullong result = a;
    result = result << 32;
    result += b;
    result = NumberOperator::transpose(result, FINAL_TRANSPOSE_TABLE, 64);
    return result;
}

ullong Des::decrypt(ullong text) {
    ullong newText = NumberOperator::transpose(text, INIT_TRANSPOSE_TABLE, 64);
    uint a = NumberOperator::left(newText);
    uint b = NumberOperator::right(newText);
    for (int i = 0; i < 15; i++) {
        uint temp = b;
        b = a ^ f(b, generator->getKey(15 - i));
        a = temp;
    }
    a ^= f(b, generator->getKey(0));
    ullong result = a;
    result = result << 32;
    result += b;
    result = NumberOperator::transpose(result, FINAL_TRANSPOSE_TABLE, 64);
    return result;
}

ullong Des::f(uint b, ullong k) {
    ullong eb = NumberOperator::transpose(b, EXTEND_TEXT_TABLE, 48);
    eb ^= k;
    uint result = 0;
    for (int i = 0; i < 8; i++) {
        uint sixBits = eb & 0x3f;
        int raw = sixBits >> 4;
        int column = sixBits & 0xf;
        result = result << 4;
        result += S[i][raw][column];
        eb = eb >> 6;
    }
    result = NumberOperator::transpose(result, TRANSPOSE_FRAGMENTS_TABLE, 32);
    return result;
}
