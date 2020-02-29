#include "stack.h"

template<class t>
stack<t>::stack(int n)
{
	size=n;
	values=new t[size];
	index=-1;
}

template<class t>
int stack<t>::isfull()
{
	if((index+1)==size)
		return 1;
	else 
		return 0;
}

template<class t>
int stack<t>::isempty()
{
	if(index==-1)
		return 1;
	else 
		return 0;
}

template<class t>
void stack<t>::push(t data )
{
	if(!stack<t>::isfull())
	{
	 index=index+1;
	 values[index]=data;
	}
}

template<class t>
t stack<t>::pop()
{
	t val=-1;
	if(!stack<t>::isempty())
	{
	 val=values[index];
	 index=index-1;
	}
	else
	{
	 cout<<"\nstack is empty\n";
	}
	return val;
}

template<class t>
t stack<t>::top_value()
{
	t val=-1;
	if(!stack<t>::isempty())
	{
	 val=values[index];
	 //index=index-1;
	}
	else
	{
	 cout<<"\nstack is empty\n";
	}
	return val;
}

/*
int main()
{
	int n,data;
	cout<<"enter the number of elements in the stack:";
	cin>>n;
	stack<int> s1(n+1);
	for(int i=1;i<=n;i++)
	{
	 cout<<"\nenter value:";
	 cin>>data;
	 s1.push(data);
	}
	cout<<"\nthe elements of stack are:";
	for(int i=1;i<=n;i++)
	{
	 data=s1.pop();
	 cout<<data<<" ";
	}
	cout<<endl;
}*/

template class stack<int>;
template class stack<float>;


