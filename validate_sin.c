#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
    if (argc != 2) { /* must has one argument, no more no less */
        return 1;
    }

    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
    int sin = strtol(argv[1], NULL, 10);
    int sin_array[9];

    /* valid SIN has the form of 9 digits and matches the pattern */
    if (!populate_array(sin, sin_array) && !check_sin(sin_array)) {
        printf("Valid SIN\n");
    } else {
        printf("Invalid SIN\n");
    }
  
    return 0;
}
