#include <iostream>
#include "des.h"

using namespace std;

#define ullong unsigned long long

int main()
{
    ullong key1 = 0xE0FEE0FEF1FEF1FE;
    ullong key2 = 0xFEE0FEE0FEE1FEE1;
    ullong text = 0xf000000000000001;
    Des des;
    ullong encr = des.encrypt(text, key1);
    printf("encrypted = %llx\n", encr);
    printf("decrypted = %llx\n", des.decrypt(encr, key2));
    return 0;
}

