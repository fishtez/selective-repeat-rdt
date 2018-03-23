// globals.h

#ifndef GLOBALS_H
#define GLOBALS_H

#define MIN_PORTNO 1024
#define MAX_PORTNO 65535

// in terms of bytes, unless otherwise specified
#define PACKET_SIZE 1024 //includes header
#define HEADER_SIZE 8
#define MAX_PAYLOAD 1016

#define MAXBUFLEN 1024

#define INITIAL_SEQ_NUM 0
#define MAX_SEQ 30720 // can fit in uint16_t
#define DEFAULT_WINDOW_SIZE 5120 //default
#define RTO 500 //ms (milliseconds)
#define OUT_FILE_NAME received.data


#define NONE 0
#define SYN 1
#define SYNACK 2
#define ACK 3
#define FIN 4
#define FINACK 5
#define FILE_NOT_FOUND 6

#endif // !GLOBALS_H