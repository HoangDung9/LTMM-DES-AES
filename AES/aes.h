#ifndef AES_H
#define AES_H
#include <stdint.h>

void aes_encrypt(uint8_t plaintext[16], uint8_t key[16],uint8_t ciphertext[16]);
void aes_decrypt(uint8_t ciphertext[16], uint8_t key[16],uint8_t plaintext[16]);
void aes_encrypt_trace(uint8_t plaintext[16], uint8_t key[16],uint8_t ciphertext[16]);

#endif
