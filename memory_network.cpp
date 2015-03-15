// memory_network.cpp

// consists of memory_neurons
#include "memory_neuron.cpp"
#include "debugger.h"

#ifndef N
	#define N 1000
#endif

class MemoryNetwork
{
	// use array to store pointers of neurons
	// easy for search
	private:
		// all neurons are stored here
		MemoryNeuron* neurons[N];
		// it's a map, data pointers maps to neuron pointers
		// we couldn't make it a hash table, since we don't know elements
		MemoryNeuron* last_access;
		// length of neurons
		long length;
	
	public:
		MemoryNetwork()
		{
			length = 0;
			last_access = 0x000000;
		}
		~MemoryNetwork()
		{
			// release memory
			for(int i=0;i<length;i++)
			{
				delete neurons[i];
			}
		}
		// safe way to get neuron by id
		long get_value(long id)
		{
			if(this==0x000000)
			{
				cout<<"Error Occurs In Function [get_neuron]: Object is Null Pointer!"<<endl;
				return 0;
			}
			if(id>=length)
			{
				cout<<"Error Occurs In Function [get_neuron]: id exceeds max length!"<<endl;
				return 0;
			}
			return neurons[id]->get_value();
		}
		// safe way to get neuron by id
		long get_conn(long id)
		{
			if(this==0x000000)
			{
				cout<<"Error Occurs In Function [get_neuron]: Object is Null Pointer!"<<endl;
				return 0;
			}
			if(id>=length)
			{
				cout<<"Error Occurs In Function [get_neuron]: id exceeds max length!"<<endl;
				return 0;
			}
			return neurons[id]->get_conn();
		}
		// train the network
		int train(long id)
		{
			// if there's one matched, just get it
			if(id<length)
			{
				MemoryNeuron* mn = neurons[id];
				if(last_access!=0x000000)
				{
					last_access->link_to(mn);
				}
				last_access = mn;
			}
			else
			{
				// establish a new neuron
				if(id>N)
				{
					// if exceeds max memory limit, report it and cease the process
					cout<<"MemoryNetwork Memory Full! Cannot Create New MemoryNeuron!"<<endl;
					return 1;
				}
				
				MemoryNeuron* mn = new MemoryNeuron(id);
				neurons[id] = mn;
				if(last_access!=0x000000)
				{
					last_access->link_to(mn);
				}
				last_access = mn;
				length ++;
			}
			
			return 0;
		}
		
		// get length of neurons
		long get_length()
		{
			return length;
		}
		
		// predict the next number within trend
		MemoryNeuron* guess()
		{
			trace("Entering memory_neuron.guess");
			// search for neighbored node list of current node
			trace("last_access value is:");
			trace(last_access->get_value());
			NodeList<long>* neighbor = last_access->get_links();
			trace("last_access node has connections:");
			trace(last_access->get_conn());
			trace("last_access node has links:");
			trace(last_access->get_links()->get_length());
			long dgr = 0L;
			long fid = 0L;
			
			trace("Entering neighbor.rewind Function");
			neighbor->rewind();
			trace("rewind is done");
			
			trace("enter while loops");
			int tick = neighbor->get_length();
			while(tick>0)
			{
				tick --;
				trace("Next exist:");
				Node<long>* nn = neighbor->yield();
				long cid = nn->data;
				trace("its value:");
				trace(cid);
				long d = nn->conn;
				trace("its conn:");
				trace(d);
				if(dgr<d)
				{
					dgr = d;
					fid = cid;
				}
			}
			// reset the flag
			neighbor->rewind();
			
			// return with chosen neuron
			return neurons[fid];
		}
		
	
};



