/*** Function: Create Memory Neuron
**** Author  : Chao Xiang
**** Version : 2014
**** 
**/
#include "iostream"
#include "memory_network.cpp"
#include "debug/debugger.h"

class NumberMemory
{
	private:
		// N is defined memory usage limit
		int data[N];
		MemoryNetwork network;
	public:
		NumberMemory()
		{
			network = MemoryNetwork();
		}
		
		~NumberMemory()
		{
			// some memory release process goes here
		}
	
		// return processing result status: true->success, false->failure
		bool train(int trainee)
		{
			if(this==0x000000)
			{
				cout<<"Error Occurs In Function [train], Object is Null!"<<endl;
				return false;
			}
			// check if memory exceeds limit
			long len = network.get_length();
			if(len>=N)
			{
				cout<<"Warning: Network Memory Usage is Full, Cannot Train New Element!"<<endl;
				return false;
			}
			// if trainee matched with any data item
			long id = 0;
			bool find = false;
			
			for(int i=0;i<len;++i)
			{
				if(data[i]==trainee)
				{
					find = true;
					id = i;
					break;
				}
			}
			
			if(!find)
			{
				// this is a new element
				if(len==N-1)
				{
					cout<<"Warning: Network Memory Usage is Full, Cannot Train New Element!"<<endl;
					return false;
				}
				// add new element
				id = len;
			}
			data[id] = trainee;
			network.train(id);
			
			return true;
		}
		
		
		// a debug tool function
		bool dump()
		{
			if(this==0x000000)
			{
				cout<<"Error Occurs In Function [train], Object is Null!"<<endl;
				return false;
			}
			
			long len = network.get_length();
			for(int i=0;i<len;++i)
			{
				cout<<"neuron [value, conn] at "<<i<<"-"<<data[i]<<"-"<<network.get_conn(i)<<endl;
			}
			return true;
		}
		
		// predict the next one
		int guess()
		{
			trace("Entering number_memory.guess");
			long cid = network.guess()->get_value();
			return data[cid];
		}
		
};


