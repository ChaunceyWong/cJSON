/*
 * SonarQube Cloud security-test sample.
 *
 * This file intentionally contains a vulnerable array access so that you can
 * test whether your C/C++ analysis setup detects user-controlled array indexes.
 *
 * DO NOT use this code in production.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_value(int argc, char **argv)
{
    int values[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }

    /* Potentially untrusted input: no range validation is performed. */
    int index = atoi(argv[1]);

    /* INTENTIONALLY VULNERABLE: index can be negative or >= 10. */
    printf("values[%d] = %d\n", index, values[index]);

    return 0;
}

int main(int argc, char **argv)
{
    return read_value(argc, argv);
}
