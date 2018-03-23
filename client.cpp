// client.cpp
/* based upon https://beej.us/guide/bgnet/ */
#include "globals.h"
//#include "Packet.h"
//#include "SR_protocol.h"
#include "utilities.h"
#include <cerrno>
#include <cstdio> /* fprintf, perror */
#include <cstdlib> /* atoi */
#include <cstring> /* strlen */
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> /* gai_strerror, etc */
#include <unistd.h> /* close */

int main( int argc, char *argv[] ){
    if (argc < 4) {
        std::cerr << "Required arguments: hostname, server port number, name of requested file.\n";
        exit(1);
    }
    char* hostname = argv[1];
    int portnum = atoi(argv[2]);
    char* filename = argv[3];
	// prints message and exits if out of range.
	valid_portnum(portnum);

	// set up socket
	int sockfd, rv, numbytes;
	struct addrinfo hints, *servinfo, *p;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(hostname, portnum, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }

    if ((numbytes = sendto(sockfd, filename, strlen(filename), 0,
             p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }

    freeaddrinfo(servinfo);

    printf("talker: sent %d bytes to %s\n", numbytes, hostname);
    close(sockfd);
	
	
	return 0;
} //end main()

