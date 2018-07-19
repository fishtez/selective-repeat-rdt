// Packet.cpp

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
#include <cstdint> /* uint16_t */
#include <time.h> /* timespec, etc */

Packet::Packet(uint16_t seqnum, uint16_t WND, uint8_t flag,
				uint8_t b_ACKed, uint16_t payload_size, char* payload)
	: m_seqnum(seqnum), m_WND(WND), m_flag(flag), b_ACKed(b_ACKed),
		m_payload_size(payload_size), m_payload(payload)
{}

Packet::~Packet(){
	if (m_payload != NULL)
		delete[] m_payload;
}
