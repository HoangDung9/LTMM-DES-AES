#include "des.h"
#include <inttypes.h>

// Ham in 64 bit nhi phan
void print_binary64(uint64_t value){
    for (int i = 63; i >= 0; i--) {
        printf("%d", (int)((value >> i) & 1)); }
    printf("\n");
}

uint64_t Nhap_plaintext()
{
    uint64_t plaintext = 0;
    printf("Nhap plaintext (hex): ");
    scanf("%" SCNx64, &plaintext);
    return plaintext;
}

uint64_t Nhap_key()
{
    uint64_t key = 0;
    printf("Nhap key (hex): ");
    scanf("%" SCNx64, &key);
    return key;
}