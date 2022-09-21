#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include <openssl/sha.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

typedef struct _transaction {
    uint32_t from;
    uint32_t to;
    uint32_t value;
} transaction;

typedef struct _block {
    unsigned char prev_hash[SHA256_DIGEST_LENGTH];
    uint32_t timestamp;
    uint32_t nonce;
    uint32_t difficulty;
    uint32_t transactionsLen;
    transaction *transactions;
} block;

void addTransaction(
        block *targetBlock,
        uint32_t from, uint32_t to, uint32_t value);

void hashBlock(block *blockToHash, unsigned char hash[SHA256_DIGEST_LENGTH]);

uint32_t mineBlock(block blockToMine);

void printBlock(block current_block, uint32_t block_idx);
