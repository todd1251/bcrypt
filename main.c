#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bcrypt.h"

int main(int argc, char *argv[])
{

    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];

    if (argc != 2 && argc != 3)
    {
        fprintf(stderr, "usage: %s <plaintext> [<salt>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc == 2) 
    {
        bcrypt_gensalt(12, salt);
        bcrypt_hashpw(argv[1], salt, hash);
        printf("%s\n", hash);
    }
    else 
    {
        bcrypt_hashpw(argv[1], argv[2], hash);
        printf("Expected: %s\n", argv[2]);
        printf("  Actual: %s\n", hash);
        if (strcmp(argv[2], hash) == 0) 
        {
            printf("The password matches\n");
        }
        else 
        {
            printf("The password does NOT match\n");
        }
    }
    
    return 0;
}
