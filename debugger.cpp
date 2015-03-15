#include "debugger.h"
#include <iostream>

using namespace std;

#ifdef _DEBUG_
	// define debug method
	void trace(const char* msg)
	{
		cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(int msg)
	{
		cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(long msg)
	{
		cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(void)
	{
		cout<<endl;
	}
#endif

#ifndef _DEBUG_
	// define debug method
	//template <class msg_type>
	void trace(const char* msg)
	{
		//cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(int msg)
	{
		//cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(long msg)
	{
		//cout<<"DEBUG: "<<msg<<endl;
	}
	void trace(void)
	{
		//cout<<"DEBUG: "<<msg<<endl;
	}
#endif
