// Packet.h

#ifndef PACKET_H
#define PACKET_H

#include "globals.h"
#include <cstdint> /* uint16_t */
#include <time.h> /* timespec, etc */

struct Packet {

    Packet(uint16_t seqnum, uint16_t WND, uint8_t flag,
    		uint8_t b_ACKed, uint16_t payload_size, char* payload);

    ~Packet();

    uint16_t m_seqnum;
    uint16_t m_WND;
    uint8_t m_flag;
    uint8_t b_ACKed;
    uint16_t m_payload_size;
    struct timespec send_time;
    char* m_payload = NULL;

};


#endif // !PACKET_H
