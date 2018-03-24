// SR_protocol.h

#ifndef SR_PROTOCOL_H
#define SR_PROTOCOL_H

#include "globals.h"
#include <cstdint> /* uint16_t */
#include <fstream> /* also includes iostream */
#include <map>
#include <queue>
#include <string>
#include <vector>

// abstract base class
class SR_protocol{
public:
	SR_protocol(){}
	
	virtual ~SR_protocol(){}

	/* setter functions *************************/
	void set_filename(std::string name){ m_filename = name; }
	bool set_send_base(uint16_t new_base); // includes bounds check
	bool set_rcv_base(uint16_t new_base); // includes bounds check
	
	// i think these aren't needed. redundant. just use set_send/rcv
/* 	// This increments and returns the new value, to save an extra get call.
	// checks bounds
	uint16_t incr_send_base();
	uint16_t incr_rcv_base(); */

	/* getter functions ************************/
	std::string get_filename(){ return m_filename; }
	uint16_t get_send_base(){ return m_send_base; }
	uint16_t get_rcv_base(){ return m_rcv_base; }
	
	/* pure virtual do stuff functions ************** */
	virtual bool handshake()=0;
	virtual bool send_data()=0;
	virtual bool receive_data()=0;
	virtual void report_packet_sent(uint16_t seq_num, uint16_t WND,
									bool is_retransmit, uint8_t flagBit)=0;
	virtual bool finish()=0;
	
	/* general do stuff functions ******************* */		
	uint16_t incr_seq_num(uint16_t old_seq_num, uint16_t incr_size);	
	void report_packet_received(uint16_t seq_num);
	
protected:	
	std::fstream m_file;
	int m_file_length;
	std::queue<std::map<uint16_t, Packet>::iterator> m_unsentQ;
	std::queue<std::map<uint16_t, Packet>::iterator> m_retransQ;
	std::vector<std::map<uint16_t, Packet>> m_packmap_vec;
	
private:
	std::string m_filename;
	uint16_t m_send_base = 0;
	uint16_t m_rcv_base = 0; 
};

#endif // !SR_PROTOCOL_H
