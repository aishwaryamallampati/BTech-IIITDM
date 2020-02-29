#include "queue.h"

template<class t>
queue<t>::queue(int n)
{
	size=n;
	values=new t[size];
	front=0;
	back=0;
}

template<class t>
int queue<t>::isfull()
{
	if((back+1)%size==front)
		return 1;
	else 
		return 0;
}

template<class t>
int queue<t>::isempty()
{
	if(back==front)
		return 1;
	else 
		return 0;
}

template<class t>
void queue<t>::enqueue(t data )
{
	if(!queue<t>::isfull())
	{
	 values[back]=data;
	 back=(back+1)%size;
	}
}

template<class t>
t queue<t>::dequeue()
{
	t val=-1;
	if(!queue<t>::isempty())
	{
	 val=values[front];
	 front=(front+1)%size;
	}
	else
	{
	 cout<<"\nqueue is empty\n";
	}
	return val;
}

/*
int main()
{
	int n,data;
	cout<<"enter the number of elements in the queue:";
	cin>>n;
	queue<int> q1(n+1);
	for(int i=1;i<=n;i++)
	{
	 cout<<"\nenter value:";
	 cin>>data;
	 q1.enqueue(data);
	}
	cout<<"\nthe elements of queue are:";
	for(int i=1;i<=n;i++)
	{
	 data=q1.dequeue();
	 cout<<data<<" ";
	}
	cout<<endl;
}*/

template class queue<int>;
template class queue<float>;
