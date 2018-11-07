// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
    int i = 0;

    for (i = 8; i > -1; --i) { /* iterate all 9 digits */
        if (!sin) { /* less than 9 digits */
            return 1;
        }
        /* take one digit */
        sin_array[i] = sin % 10;
        sin /= 10;
    }

    if (sin) { /* more than 9 digits */
        return 1;
    }

    return 0;
}

// TODO: Implement check_sin
/* 
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
    int result[9];
    int product;
    int sum = 0;
    int i;

    /* iterate all 9 digits */
    for (i = 0; i < 9; ++i) {
        if (i % 2) { /* double every other digit */
            product = 2 * sin_array[i];
            if (product > 9) { /* greater than 9 */
                /* sum up 2 digits */
                result[i] = product % 10 + product / 10;
                /* alternative way to get the same result */
                // result[i] = product - 9;
            } else {
                result[i] = product;
            } 
        } else {
            result[i] = sin_array[i];
        }
    }

    /* sum up all 9 digits */
    for (i = 0; i < 9; ++i) {
        sum += result[i];
    }

    /* valid only if the sum is a multiple of 10 */
    if (sum % 10) {
        return 1;
    }

    return 0;
}
