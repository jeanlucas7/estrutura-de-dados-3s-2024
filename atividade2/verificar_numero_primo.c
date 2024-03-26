#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);
    if (num <= 1) {
        printf("false\n");
        return 0;
    }

    if (num <= 3) {
        printf("true\n");
        return 0;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        printf("false\n");
        return 0;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");
    return 0;
}
