#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int hash_mult(char keys[]);
int hash_bitw(char keys[]);


int main(){
    char keys[50];
    printf("Input keys: \n");
    scanf("%s", keys);

    printf("HashMult: %d\n", hash_mult(keys));
    printf("HashBitw: %d\n", hash_bitw(keys));

    return 0;
}

int hash_mult(char keys[]){
    return (keys[0] - 96) + ((keys[1] - 96) * 32) + ((keys[2] - 96) * (32 * 32));
}

int hash_bitw(char keys[]){
    return (keys[0] - 96) | ((keys[1] - 96) << 5) | ((keys[2] - 96) << 5 << 5);
}
