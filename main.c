#include <stdio.h>
#include <stdlib.h>
#include "bcrypt.h"

int main(int argc, char *argv[])
{

    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <plaintext>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    bcrypt_gensalt(12, salt);
    bcrypt_hashpw(argv[1], salt, hash);

    printf("%s\n", hash);
    
    return 0;
}
