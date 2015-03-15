// memory_neuron_test.cpp

// test the class MemoryNeuron

#include "iostream"
#include "memory_neuron.cpp"

int t_main(int argc, const char** argv)
{
	using namespace std;
	
	// create some neuron
	MemoryNeuron* mn1 = new MemoryNeuron(1);
	MemoryNeuron* mn2 = new MemoryNeuron(2);
	MemoryNeuron* mn3 = new MemoryNeuron(3);
	MemoryNeuron* mn4 = new MemoryNeuron(4);
	MemoryNeuron* mn5 = new MemoryNeuron(5);

	// initial structure
	mn2->link_to(mn1);
	mn3->link_to(mn2);
	mn4->link_to(mn2);
	mn5->link_to(mn4);
	mn5->link_to(mn1);
	mn3->link_to(mn5);
	mn5->link_to(mn2);
	mn2->link_to(mn5);
	mn3->link_to(mn2);
	
	// check each function
	// check get_value function
	//cout<<"mn3 value is :"<<mn3->get_value()<<endl;
	//cout<<"mn5 value is :"<<mn5->get_value()<<endl;
	if(mn3->get_value()==3&&mn5->get_value()==5)
	{
		cout<<"MemoryNeuron::get_value(void) test passed!"<<endl;
	}
	// check get_conn function
	//cout<<"mn3 conn is: "<<mn3->get_conn()<<endl;
	//cout<<"mn5 conn is: "<<mn5->get_conn()<<endl;
	if(mn3->get_conn()==3&&mn5->get_conn()==3)
	{
		cout<<"MemoryNeuron::get_conn(void) test passed!"<<endl;
	}
	// check get_conn(id) function
	//cout<<"mn3 to mn2, conn is: "<<mn3->get_conn(2)<<endl;
	//cout<<"mn5 to mn2, conn is: "<<mn5->get_conn(2)<<endl;
	if(mn3->get_conn(2)==2&&mn5->get_conn(2)==1)
	{
		cout<<"MemoryNeuron::get_conn(long id) test passed!"<<endl;
	}
	
	return 0;
	
}
