// node_list.cpp
#include "debug/debugger.h"
#include "iostream"
#include "node.cpp"

#define	OK	0
#define	ERROR	1
#define	WARNNING	2

// pointer stack size
#define _STACK_SIZE_ 100

using namespace std;

template <class value_type> class NodeList
{
private:
		Node<value_type>* head;
		Node<value_type>* tail;
		Node<value_type>* flag;
		// if one program to change the pointer, we push it back
		// if you need to restore the iterator, just pop it out
		Node<value_type>* _p[_STACK_SIZE_];
		int p_size;
		long length;
		

public:
		// constructor 1
		NodeList()
		{
			length = 0;
			head = tail = flag = 0x000000;
			p_size = 0;
		}
		// constructor 2
		NodeList(value_type val)
		{
			length = 1;
			tail = flag = head = new Node<value_type>(val);
			p_size = 0;
		}
		~NodeList()
		{
			delete head;
		}
	
		// get length of list
		long get_length()
		{
			// if this is a null pointer we return bad signal
			if(this==0x000000)
			{
				cout<<"When Try To Use Function [get_length], Error Occurs, Object is NULL!"<<endl;
				return 0;
			}
			return length;
		}
		
		// add element
		int add(value_type next_value)
		{
			// if this is a null pointer we return bad signal
			if(this==0x000000)
			{
				cout<<"When Try To Use Function [add], Error Occurs, Object is NULL!"<<endl;
				// return error code
				return 1;
			}
			
			if(length==0)
			{
				head = tail = flag = new Node<value_type>(next_value);
			}
			else
			{
				tail->next = new Node<value_type>(next_value);
				tail = tail->next;
			}
			++ length;
			
			return 0;
		}
		
		// get next element of current flag
		Node<value_type>* yield()
		{
			// if this is a null pointer we return bad signal
			if(this==NULL)
			{
				cout<<"When Try To Use Function [next], Error Occurs, Object is NULL!"<<endl;
				return NULL;
			}
			
			Node<value_type>* res;
			res = flag;
			flag = flag->next;
#ifdef _DEBUG_
			cout<<"flag address:"<<int(flag)<<endl;
#endif
			return res;
		}
		
		// reset flag
		int rewind()
		{
			// if this is a null pointer we return bad signal
			if(this==NULL)
			{
				cout<<"When Try To Use Function [rewind], Error Occurs, Object is NULL!"<<endl;
				// return error code
				return ERROR;
			}
			flag = head;
			return OK;
		}
		
		Node<value_type> *get_head()
		{
			// if this is a null pointer we return bad signal
			if(this==0x000000)
			{
				cout<<"When Try To Use Function [get_head], Error Occurs, Object is NULL!"<<endl;
				// return error code
				return 0x000000;
			}
			return head;
		}
		
		// save current state to stack
		bool save_state()
		{
			// push state
			_p[p_size] = flag;
			p_size++;
		}
		// restore state from stack
		bool restore_state()
		{
			// pop state
			flag = _p[p_size];
			p_size--;
		}
};
