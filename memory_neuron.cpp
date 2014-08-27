// memory_neuron.h
#include "iostream"
#include "node_list.cpp"

class MemoryNeuron
{
	private:
		// alone node flag
		bool alone;
		// like index of neuron, which stands for label in the real world.
		long value;
		// linked list is a list of linked node.
		NodeList<long> *links;
	
	public:
		// constructor
		MemoryNeuron(long _value)
		{
			alone = true;
			value = _value;
			links = 0x000000;
		}
		
		// recycle memory
		~MemoryNeuron()
		{
			// something to do
			// release memory taken by links
			delete links;
		}
		
		int link_to(MemoryNeuron* neuron)
		{
			// get the value of neuron
			long neuron_value = neuron->get_value();
			
			if(alone)
			{
				links = new NodeList<long>(neuron_value);
			}
			else
			{
				// check if link already exist
				bool find = false;
				links->rewind();
				long n = links->get_length();
				while(n>0)
				{
					n--;
					// if matched, add the connectivity
					Node<long>* yield = links->yield();
					if(neuron_value==yield->data)
					{
						yield->grow();
						find = true;
						break;
					}
				}
				// if not matched
				if(!find)
				{
					links->add(neuron_value);
				}
				links->rewind();	
			}
			// this is not a stand-alone node any longer
			alone = false;
			
			return 0;
		}
		
		long get_value()
		{
			return value;
		}
		
		// get all connectivity
		long get_conn()
		{
			// add all sub node connectivity
			links->rewind();
			long conn = 0L;
			long n = links->get_length();
			while(n>0)
			{
				n--;
				Node<long>* yield = links->yield();
				conn +=  yield->conn;
			}
			links->rewind();
			
			return conn;
		}
		
		// get certain connectivity of certain node
		long get_conn(long cid)
		{
			// reset flag before iterator
			if(links->rewind()!=OK)
			{
				cout<<"Error in Rewind Function."<<endl; 
				return 0; 
			}
			long conn = 0L;
			// prevent unstopped loop
			long t = links->get_length();
			while(t>0)
			{
				t--;
				Node<long>* yield = links->yield();
				if(yield->data==cid)
				{
					conn = yield->conn;
				}
			}
			// reset the flag
			links->rewind();
			
			return conn;
		}
		
		NodeList<long>* get_links()
		{
			return links;
		}
	
};


