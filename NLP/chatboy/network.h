// network.h
#include "string.h"

class network
{

public:
	void initialize();					// initialize the network with some random state
	void switchmode();					// switch from chat mode to practice moode or inversly
	bool practice(string str);			// practice the network by original text
	string chat(string str);			// request with text and response with text
	string compose();					// compose a new line all by herself

	string rate(string str);			// rate the response, and she response back
	bool checkstate();					// check her state, normally sleep, digest, listen, compose
	bool sleep();						// make her sleep and do nothing, all arguments are stored in disk
	bool wakeup();						// make her wake up and start listening to request
	bool takearest();					// mode switch to rest and begin to digest things learnt in daytime

	bool selfheal();					// fix internal network, check network completeness.
	bool forget(string keywords);		// forget staff concerning keywords

};

