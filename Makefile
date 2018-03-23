# Makefile for selective-repeat-rdt

CXXFLAGS = -g -std=c++11  -Wall -Wextra
LDFLAGS = 
OBJS = $(SOURCE:%.cpp=%.o)
DEFAULT_PORT = 8000
DEFAULT_HOSTNAME = localhost
DEFAULT_TESTFILE = testfile
SOURCE = client.cpp server.cpp Packet.cpp SR_protocol_server.cpp SR_protocol_client.cpp utilities.cpp

default: clean client server
	
# executable
client: client.o Packet.o utilities.o
#	$(CXX) $(CXXFLAGS) -o client client.o SR_protocol_client.o Packet.o utilities.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o client client.o Packet.o utilities.o $(LDFLAGS)

# executable
server: server.o Packet.o utilities.o
#	$(CXX) $(CXXFLAGS) -o server server.o SR_protocol_server.o Packet.o utilities.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o server server.o Packet.o utilities.o $(LDFLAGS)

# objects
client.o: client.cpp utilities.h  Packet.h globals.h
	$(CXX) $(CXXFLAGS) -c client.cpp 

server.o: server.cpp utilities.h Packet.h globals.h
	$(CXX) $(CXXFLAGS) -c server.cpp 

# SR_protocol_server.o: SR_protocol_server.cpp SR_protocol.h globals.h
# $(CXX) $(CXXFLAGS) -c SR_protocol_server.cpp  
	
# SR_protocol_client.o: SR_protocol_client.cpp SR_protocol.h globals.h 
# $(CXX) $(CXXFLAGS) -c SR_protocol_client.cpp 

Packet.o: Packet.cpp Packet.h globals.h
	$(CXX) $(CXXFLAGS) -c Packet.cpp 

utilities.o: utilities.cpp utilities.h globals.h 
	$(CXX) $(CXXFLAGS) -c utilities.cpp 

# basic tests / default run	
.PHONY: tserver
tserver: server
	./server $(DEFAULT_PORT)
	
.PHONY: tclient
tclient: client
	./client $(DEFAULT_HOSTNAME) $(DEFAULT_PORT) $(DEFAULT_TESTFILE)
#	diff $(DEFAULT_TESTFILE) received.data

.PHONY: clean	
clean:
	-rm -f $(OBJS) *~ client server
