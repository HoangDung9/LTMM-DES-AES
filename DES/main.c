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
int main() {
    uint64_t plaintext;
    uint64_t key;
    uint64_t k[16];
    plaintext = Nhap_plaintext();
    key = Nhap_key();

    gen_subkey(key, k);
    uint64_t IP_output = IP_function(plaintext);

    printf("IP output binary: ");
    print_binary64(IP_output);
    printf("\n");

    // Di qua 16 vong Feistel
    uint64_t round_output = round_16(IP_output, k);

    printf("Round 16 output binary: ");
    print_binary64(round_output);
    printf("\n");
    
    uint64_t ciphertext = IP_inverse_function(round_output);
    printf("Ciphertext: %016" PRIX64 "\n", ciphertext);
    printf("Ciphertext in binary: ");
    print_binary64(ciphertext);
    return 0;
}