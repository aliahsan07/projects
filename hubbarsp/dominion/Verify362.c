/*
 * Verify362.c
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Verify362.h"

void VerificationFailure(const char *exp, const char *file, const char *baseFile, int line) {
  if (!strcmp(file, baseFile)) {
    fprintf(stderr, "Verify362(%s) failed in file %s, line %d\n", exp, file, line);
  } else {
    fprintf(stderr, "Verify362(%s) failed in file %s (included from %s), line %d\n", exp, file, baseFile, line);
  }
  exit(EXIT_FAILURE);
}
