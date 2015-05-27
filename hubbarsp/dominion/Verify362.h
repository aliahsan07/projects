/*
 * Verify362.h
 *
 *  Created on: April 22, 2015
 *      Author: Spencer Hubbard
 */

#ifndef VERIFY362_H_
#define VERIFY362_H_

// wrapper for assert that permits side-effects within Verify362 statement
// borrowed from: http://www.acm.uiuc.edu/sigops/roll_your_own/2.a.html

void VerificationFailure(const char *exp, const char *file, const char *basefile, int line);

#define Verify362(exp) if (exp) ; \
  else VerificationFailure(#exp, __FILE__, __BASE_FILE__, __LINE__)

#endif /* VERIFY362_H_ */
