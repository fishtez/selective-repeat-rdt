// utilities.h

#ifndef UTILITIES_H
#define UTILITIES_H

#include "globals.h"
#include <cstdio> /* ssize_t, etc */

bool is_okay();
// void testPacketRelations();
long timeDiff(struct timespec *start_time, struct timespec *end_time);
void valid_portnum(const char* portnum);


#endif // !UTILITIES_H
