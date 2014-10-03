// network.h
#include <string>

// type defintion
enum network_mode_t 
{
	SLEEP = 0,
	LISTEN = 1,
	DIGEST = 2,
	COMPOSE = 3
};


class network
{
private:
	network_mode_t mode;

public:
	void initialize();							// initialize the network with some random state
	void switchmode();							// switch from chat mode to practice moode or inversly
	bool practice(std::string str);				// practice the network by original text
	std::string chat(std::string str);			// request with text and response with text
	std::string compose();						// compose a new line all by herself

	std::string rate(std::string str);			// rate the response, and she response back
	bool checkstate();							// check her state, normally sleep, digest, listen, compose
	bool sleep();								// make her sleep and do nothing, all arguments are stored in disk
	bool wakeup();								// make her wake up and start listening to request
	bool takearest();							// mode switch to rest and begin to digest things learnt in daytime

	bool selfheal();							// fix internal network, check network completeness.
	bool forget(std::string keywords);			// forget staff concerning keywords
	bool reset();								// reset memory of network

};

