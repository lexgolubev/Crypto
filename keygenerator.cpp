#include "keygenerator.h"

DesRoundKeyGenerator::DesRoundKeyGenerator(ullong key) : key(key) {
    ullong left = NumberOperator::transpose(key, TRANSPOSE_KEY_TABLE1, 28);
    ullong right = NumberOperator::transpose(key, TRANSPOSE_KEY_TABLE2, 28);
    for (int i = 0; i < 16; i++) {
        int n;
        if (i == 1 || i == 2 || i == 9 || i == 16) {
            n = 1;
        } else {
            n = 2;
        }
        left = leftCyclicShift(left, n);
        right = leftCyclicShift(right, n);
        ullong lr = (left << 28) | right;
        keys[i] = NumberOperator::transpose(lr, COMPRESS_KEY_TABLE, 48);
    }
}

ullong DesRoundKeyGenerator::getKey(int i) {
    return keys[i];
}

ullong DesRoundKeyGenerator::leftCyclicShift(ullong text, int bit) {
    ullong left = text >> (28 - bit);
    ullong right = text << bit;
    return left | right;
}
