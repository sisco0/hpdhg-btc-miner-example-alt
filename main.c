#include "functions.h"

int main(int argc, char **argv) {
    /*
     * The root block always contains
     * 0x00 as its previous hash.
     */
    block blockchain[1024];
    block currentBlock = {
        /* prev_hash */
        0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,
        /* timestamp */
        time(NULL),
        /* nonce */
        0x00000000,
        /* difficulty */
        0x00000014,
        /* transactionLen */
        0x0,
        /* transaction array */
        0x00
    };
    uint32_t wallets[] = {
        0x00001337,
        0x0000C320,
        0x12345678,
    };
    /* Add transactions */
    // Mine current block
    // Print the result
    return 0;
}

void addTransaction(
        block *targetBlock,
        uint32_t from, uint32_t to, uint32_t value)
{
    targetBlock->transactionsLen++;
    transaction newTransaction = { from, to, value };
    transaction *newTransactions = malloc(
            sizeof(transaction) * targetBlock->transactionsLen
    );
    if (targetBlock->transactions != NULL)
    {
        memcpy(
                newTransactions, targetBlock->transactions,
                sizeof(transaction) * (targetBlock->transactionsLen - 1)
        );
        free(targetBlock->transactions);
    }
    newTransactions[targetBlock->transactionsLen-1] = newTransaction;
    targetBlock->transactions = newTransactions;
}

void hashBlock(block *blockToHash, unsigned char hash[SHA256_DIGEST_LENGTH])
{
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, blockToHash, sizeof(block) - sizeof(uint32_t*));
    SHA256_Update(&sha256, blockToHash->transactions, sizeof(transaction) * blockToHash->transactionsLen);
    SHA256_Final(hash, &sha256);
}

uint32_t mineBlock(block blockToMine)
{
    uint32_t current_nonce = 0;
    /* Fill with solution */
    return current_nonce;
}

void printBlock(block current_block, uint32_t block_idx)
{
    printf("---------------------------\nBlock number: [%i]\n", block_idx);
    printf("Previous Hash:\t\t[");
    for(unsigned int k = 0; k < SHA256_DIGEST_LENGTH; k++) printf("%02x", current_block.prev_hash[k]);
    printf("]\n");
    printf("Timestamp:\t\t[%08x]\n", current_block.timestamp);
    printf("Nonce:\t\t\t[%08x]\n", current_block.nonce);
    printf("Difficulty:\t\t[%08x]\n", current_block.difficulty);
    printf("Transactions:\n");
    for (unsigned int k = 0; k < current_block.transactionsLen; k++)
    {
        printf("\t%08x -> %08x\t(%u HPFC)\n", 
                current_block.transactions[k].from,
                current_block.transactions[k].to,
                current_block.transactions[k].value
        );
    }
    printf("============================\nCalculated Hash:\t[");
    unsigned char current_hash[SHA256_DIGEST_LENGTH];
    hashBlock(&current_block, current_hash);
    for(unsigned int k = 0; k < SHA256_DIGEST_LENGTH; k++) printf("%02x", current_hash[k]);
    printf("]\n\t\t\t");
    for(unsigned int k = 0; k < SHA256_DIGEST_LENGTH; k++) {
        if (k%8==0 && k!=0) printf("\n\t\t\t");
        else if (k%4==0 && k!=0) printf("\t");
        printf(BYTE_TO_BINARY_PATTERN " ", BYTE_TO_BINARY(current_hash[k]));
    }
    printf("\n============================\n");
}
