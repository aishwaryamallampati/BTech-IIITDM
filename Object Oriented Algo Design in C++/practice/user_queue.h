//user_queue.h
#include<iostream>
#include<cstdlib>
using namespace std;

#define default_value 100

template<class t>
class user_queue
{
	public:
		user_queue(int= default_value);
		~user_queue()
		{
			delete [] values;
		}
		void enqueue(t data);
		t dequeue();
		int isempty();
		int isfull();
	private:
		int size;
		t *values;
		int front;
		int back;
};

