#include "des.h"
#include "des_tables.h"

uint64_t IP_function(uint64_t plaintext){
    uint64_t result = 0;
    for (int i = 0; i < 64; i++){
        uint64_t bit = (plaintext >> (64 - IP[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

uint64_t IP_inverse_function(uint64_t input){
    uint64_t result = 0;
    for (int i = 0; i < 64; i++){
        uint16_t bit = (input >> (64 - IP_inv[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

uint64_t E_function(uint32_t input)
{
    uint64_t result = 0;
    for (int i = 0; i < 48; i++){
        uint16_t bit = (input >> (32 - E[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

uint32_t P_function(uint32_t input)
{
    uint64_t result = 0;
    for (int i = 0; i < 32; i++){
        uint16_t bit = (input >> (32 - P[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

// Ham F
uint32_t f_function(uint32_t R, uint64_t ki)
{
    uint8_t B[8];
    uint64_t expanded_R;
    uint64_t xor;
    uint32_t sbox_result = 0;
    expanded_R = E_function(R);
    xor = expanded_R ^ ki;
    for (int i = 0; i < 8; i++){
        B[i] = (xor >> (42 - 6 * i)) & 0x3F; }

    for (int i = 0; i < 8; i++) {
        int row = ((B[i] >> 4) & 0x02) | (B[i] & 1);
        int col = (B[i] >> 1) & 0x0F;
        int sbox_i_output = S_box[i][row][col];

        sbox_result = (sbox_result << 4) | sbox_i_output;
    }

    return P_function(sbox_result);
}

uint64_t PC1_function(uint64_t key)
{
    uint64_t result = 0;

    for (int i = 0; i < 56; i++){
        uint16_t bit = (key >> (64 - PC1[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

uint64_t PC2_function(uint64_t input)
{
    uint64_t result = 0;
    for (int i = 0; i < 48; i++){
        uint16_t bit = (input >> (56 - PC2[i])) & 1;
        result = (result << 1) | bit; }
    return result;
}

// Ham dich vong trai
uint64_t left_shift(uint64_t input, int s) {
    uint64_t result = ((input << s) |
                      (input >> (28 - s))) & 0x0FFFFFFF;

    return result; }

// Ham tao ra 16 khoa con
void gen_subkey(uint64_t key, uint64_t k[16])
{
    uint64_t v;
    uint64_t C;
    uint64_t D;
    v = PC1_function(key);
    C = (v >> 28) & 0x0FFFFFFF;
    D = v & 0x0FFFFFFF;
    for (int i = 0; i < 16; i++) {
        C = left_shift(C, shift_table[i]);
        D = left_shift(D, shift_table[i]);
        k[i] = PC2_function((C << 28) | D); }
}