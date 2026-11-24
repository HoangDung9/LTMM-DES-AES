#ifndef AES_H
#define AES_H
#include <stdio.h>
#include <stdint.h>

// Ham bien doi AES
void ByteSub_function(uint8_t state[16]);
void ShiftRow_function(uint8_t state[16]);
void MixColumn_function(uint8_t state[16]);
void AddRoundKey_function(uint8_t state[16], uint8_t key[16]);

uint8_t multiply(uint8_t a, uint8_t b);

void RotWord(uint8_t word[4]);
void SubWord(uint8_t word[4]);
void gen_subkey(uint8_t key[16], uint8_t k[11][16]);

#endif