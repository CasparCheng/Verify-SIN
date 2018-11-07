#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Implement a helper named check_permissions that matches the prototype
// below.
int check_permissions(char *, char *);

int main(int argc, char **argv) {
  if (!(argc == 2 || argc == 3)) {
    fprintf(stderr, "USAGE: count_large size [permissions]\n");
    return 1;
  }

  // TODO: Process command line arguments.
  int size = 0;
  char *permissions = NULL;

  if (argc > 1) { /* one or two passed-in arguments */
    size = strtol(argv[1], NULL, 10);
  }
  if (argc > 2) { /* two passed-in arguments */
    permissions = argv[2];
  }

  // TODO Call check permissions as part of your solution to counting the files
  // to
  // compute and print the correct value.
  char tmp[32];
  int count = 0;
  int actual_size;
  char actual_permissions[32];

  /* consume the first line composed of 2 fields, i.e. the total line */
  if (scanf("%*s %s", tmp) == 1) {
    /* consume the data line composed of 9 fields */
    while (scanf("%s %*d %*s %*s %d %*s %*s %*s %s", actual_permissions,
                 &actual_size, tmp) == 3) {
      /* validate if reguler file and
         its size meets requirement and
         it has the required permissions */
      if (strlen(actual_permissions) == 10 &&
          actual_permissions[0] == '-' &&
          actual_size > size &&
          !check_permissions(actual_permissions + 1, permissions)) {
        ++count;
      }
    }
  }

  /* print the result, i.e. the number of matched lines */
  printf("%d\n", count);

  return 0;
}

int check_permissions(char *actual_permissions, char *permissions) {
  /* no permissions specified */
  if (permissions == NULL) {
    return 0;
  }

  int i;

  /* check permissions bits */
  for (i = 0; i < 9; ++i) {
    if (permissions[i] != '-' && actual_permissions[i] != permissions[i]) {
      return 1;
    }
  }

  return 0;
}
