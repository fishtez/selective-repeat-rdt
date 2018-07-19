# ** selective-repeat-rdt **

**Description:**
The purpose of this project is to implement Selective Repeat Protocol to
provide reliable data transfer over unreliable UDP (which has no delivery
    guarantees built in).

# Installation:
Currently a makefile is included with the following basic targets:
* tserver - compiles and starts the server with default port number
    (as given in makefile)
* tclient - compiles and starts the client with default hostname,
    port, and file name being requested for transfer.
* clean - delete all programs and output created by makefile

# Credits:
I based the initial client and server code on the UDP tutorial given here: https://beej.us/guide/bgnet/
