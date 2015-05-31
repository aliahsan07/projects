/*
 *  Name: Spencer Hubbard
 *  Date: 4/14/15
 *  CS 362
 *
 *  TODO: comment
 */

#include <stddef.h>  // for NULL, size_t
#include <stdbool.h> // for bool
#include <stdio.h>   // for FILE, fopen(), fclose(), fprintf(), printf()
#include <stdlib.h>  // for EXIT_SUCCESS, EXIT_FAILURE, malloc(), free(), exit(), rand(), srand()
#include <errno.h>   // for errno
#include <string.h>  // for strerror()

#include "CS362.h"

/* wrapper for assert */

void VerificationFailure(const char *exp, const char *file, const char *baseFile, int line) {
  if (!strcmp(file, baseFile)) {
    fprintf(stderr, "Verify362(%s) failed in file %s, line %d\n", exp, file, line);
  } else {
    fprintf(stderr, "Verify362(%s) failed in file %s (included from %s), line %d\n", exp, file, baseFile, line);
  }
  exit(EXIT_FAILURE);
}

/* unix style error */

void UnixError(char *msg) {
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(EXIT_FAILURE);
}

/* application error */

void AppError(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(EXIT_FAILURE);
}

/* wrappers for general utilities */

void *Malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    UnixError("Malloc error");
  }
  return ptr;
}

void Free(void *ptr) {
  free(ptr);
}

/* wrapper for library functions */

FILE *Fopen(const char * restrict filename, const char * restrict mode) {
  FILE *stream = fopen(filename, mode);
  if (stream == NULL) {
    UnixError("Fopen error");
  }
  return stream;
}

void Fclose(FILE * restrict stream) {
  int result = fclose(stream);
  if (result == EOF) {
    UnixError("Fclose error");
  }
}
