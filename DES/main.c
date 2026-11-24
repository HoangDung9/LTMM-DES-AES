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
// Ham thuc hien 16 vong Feistel
uint64_t round_16(uint64_t input, uint64_t k[16])
{
    uint32_t L = (input >> 32) & 0xFFFFFFFF;
    uint32_t R = input & 0xFFFFFFFF;
    for (int i = 0; i < 16; i++){
        uint32_t tmp = R;
        R = L ^ f_function(R, k[i]);
        L = tmp; }
    return ((uint64_t)R << 32) | L;
}