// SR_protocol.cpp

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
#include "SR_protocol.h"
#include <cstdint> /* uint16_t */
#include <map>
#include <vector>

// if out of bounds, return false
	// send_base is not changed
// else send_base is updated, returns true
bool SR_protocol::set_send_base(uint16_t new_base){
	if(new_base < 0 || new_base > MAX_SEQ)
		return false;
	else{
		m_send_base = new_base;
		return true;
	}
}

// if out of bounds, return false
	// rcv_base is not changed
// else rcv_base is updated, returns true
bool SR_protocol::set_rcv_base(uint16_t new_base){
	if(new_base < 0 || new_base > MAX_SEQ)
		return false;
	else{
		m_rcv_base = new_base;
		return true;
	}
}

// redundant?
// CURRENTLY INCREASES BY 1, NOT BY INCR_SIZE
/* // This increments and returns it, to save an extra get call.
uint16_t SR_protocol::incr_rcv_base(){
	
	uint16_t temp_rcv_base = m_rcv_base++;
	
	// bounds check
	// TODO >= ?
	if(temp_rcv_base > MAX_SEQ)
		temp_rcv_base = INITIAL_SEQ_NUM;
	
	return temp_rcv_base;
}

// CURRENTLY INCREASES BY 1, NOT BY INCR_SIZE
// This increments and returns it, to save an extra get call.
uint16_t SR_protocol::incr_send_base(){
	
	uint16_t temp_send_base = m_send_base++;
	
	// bounds check
	// TODO >= ?
	if(temp_send_base > MAX_SEQ)
		temp_send_base = INITIAL_SEQ_NUM;
	
	return temp_send_base;
} */

// currently does NOT create new map when resets num
uint16_t SR_protocol::incr_seq_num(uint16_t old_seq_num, uint16_t incr_size){
	
	uint16_t temp_seq = old_seq_num + incrSize;
	
	// TODO need to increment vector of maps?
	// bounds check
	if(temp_seq > MAX_SEQ){
		uint16_t diff = temp_seq - MAX_SEQ;
		temp_seq = INITIAL_SEQ_NUM + diff;
	}
	
	return temp_seq;
}

void SR_protocol::report_packet_received(uint16_t seq_num){
	std::cout << "Receiving packet " << seq_num << "\n";
}