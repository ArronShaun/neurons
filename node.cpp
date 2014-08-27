// node.cpp

#include "iostream"

using namespace std;


template <class data_type> class Node
{
	public:
		// data stored in the node 
		data_type data;
		// the connectivity of the node
		long conn;
		// the pointer of the next node
		Node<data_type>* next;
	
		Node(data_type _data)
		{
			data = _data;
			conn = 1;
			next = 0x000000;
		}
		~Node()
		{
			// do something to recycle memory
			delete next;
		}
		// strengthen the connectivity
		int grow()
		{
			// if this is a null pointer we return bad signal
			if(this==0x000000)
			{
				cout<<"When Try To Use Function [grow], Error Occurs, Object is NULL!"<<endl;
				// return error code
				return 1;
			}
			++ conn;
			return 0;
		}
		
};
