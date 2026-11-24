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