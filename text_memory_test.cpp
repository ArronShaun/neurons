/*** Function: Memory Neuron Test
**** Author  : Chao Xiang
**** Version : 2014
**** 
**/

#include "debugger.h"
#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "text_memory.cpp"

#ifndef TEST_SCALE
	#define TEST_SCALE 2000
#endif

using namespace std;

bool a_case();
bool normalize(string data[TEST_SCALE], int& length); 

int main(int argc, const char** argv)
{
	a_case();
	
	// use part of given data to predict the next part of it
	string data[TEST_SCALE];
	int length = 0;
	normalize(data, length);
	// use data to train the network
	/*** test from data set
	NumberMemory memo = NumberMemory();
	
	int n = 0;
	
	while(n<length-3)
	{
		if(!memo.train(data[n])) 
		{
			cout<<"Error Occurs When Trying to Train NumberMemory with "<<n<<"th number"<<endl;
			return 1;
		}
		n++;
	}
	
	// view inside the memory
	//memo.dump();
	cout<<"memory length :"<<length<<endl;
	
	//predict the next possible one:
	cout<<"Last Access Number: "<<data[length-4]<<endl;
	trace("entering Function [guess]");
	cout<<"Guess number is:"<<memo.guess()<<endl;
	trace("exiting Function [guess]");
	cout<<"The real number is:"<<data[length-3]<<endl;
	
	****/
	
	return 0;
	
}

// split string into string array
// return str_arr as array of string and n as length of strings
#ifndef _WORDS_UP_LIMIT_
	#define _WORDS_UP_LIMIT 100
#endif
bool split(string& *str_arr, int& n, const& string str)
{
	// up limit
	// not over
}

bool a_case()
{
	NumberMemory memory = NumberMemory();
	string str = "I am a boy, and I love apples, boy love apples, and it is good for boys, so it is good for me.";
	str = str.replace(",", " ,");
	str = str.replace(".", " .");
	str = str.replace("?", " ?");
	str = str.replace("!", " !");
	string *str_arr = str.split(" ");
	
	for(int i=0;i<str_arr;i++)
	{
		if(!memory.train(data[i%30])) 
		{
			cout<<"Error Occurs When Trying to Train NumberMemory with number-"<<data[i]<<endl;
			return 1;
		}
	}
	
	// debug program
	memory.dump();
	
	return true;
}

bool normalize(string data[TEST_SCALE], int& length)
{
	// process test dataset, get normalized dataset
	ifstream input("data/text_memory_data.txt"); // this file can be anything in it, you decide it yourself!
	
	//read from file and match format and store the data
	string word;
	input>>word;
	
	// "\0" is meant to be the end
	while(line.length()>1&&length<TEST_SCALE)
	{
		data[length] = word;
		
		length = length +1;
		word = "";
		input>>word;
	}
	
	if(length==TEST_SCALE)
	{
		return false;
	}
	else
	{
		return true;
	}
	
	return true;
}


