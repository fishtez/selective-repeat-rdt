// utilities.cpp

// template for function descriptions
/****************************************************************************
Name: 
Arguments: 
Returns: 
Precondition(dependencies):
Postcondition(guarantees upon return):
Description: 
****************************************************************************/
#include "globals.h"
#include "Packet.h"
#include "utilities.h"
#include <cassert>
#include <cstdlib> /* srand */
#include <iostream>
#include <time.h> /* timespec, etc */
#include <vector>



long timeDiff(struct timespec *start_time, struct timespec *end_time){
	
	long ns, ms;
	ns = end_time->tv_nsec - start_time->tv_nsec;
	ms =  ns/1000000.0; //convert nanoseconds to milliseconds	
	
	return ms;
}

bool is_okay(){
	srand(time(NULL));
	
	int chance = rand() % 10 + 1;
	if (chance <= 4)
		return false;
	else
		return true;
	
}

void testPacketRelations(){
	std::vector<char> payload;
	Packet p1(payload, 1, 0, 0, 0);
	Packet p2(payload, 2, 0, 0, 0);
	Packet p3(payload, 3, 0, 0, 0);
	Packet p4(payload, 1, 0, 0, 0);
	
	assert(p3 > p1);
	assert(p3 != p1);
	assert(p4 == p1);
	assert(p4 >= p1);
	assert(p4 <= p1);
	assert(p1 < p2);
	assert(p2 >= p1);
	assert(p4 == p4);	
	std::cerr << "Packet relational operators passed tests.\n";
}

/*==========================================================================*/
//	functions used by both client and server
/*==========================================================================*/
void valid_portnum(ssize_t portnum){
	if(portnum < MIN_PORTNO || portnum > MAX_PORTNO){
		fprintf(stderr, "May not use port number: %d\n", portnum);
		exit(1);
	}
}


/*==========================================================================*/
//	functions used by client ONLY
/*==========================================================================*/

/*==========================================================================*/
//	functions used by server ONLY
/*==========================================================================*/





