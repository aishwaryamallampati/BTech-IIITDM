#include<iostream>
#include<cstdlib>
#include<math.h>
#include<stdlib.h>
#include "queue.h"
using namespace std;
void print(int *s,int set_size, int start,int end,int index);
queue<int> int_q1(50);

int main()
{
char prev[100];
int s[100],size;
cout<<"\nenter the size:";
cin>>size;
cout<<"enter the elements:";
for(int i=0;i<size;i++)
{
//int_q1.display();
cin>>s[i];

}
/*for(int i=0;i<size;i++)
{
//int_q1.display();
cout<<s[i];
}
cout<<endl;*/
print(s,size,0,2,0);
}

void print(int *s,int set_size, int start,int end,int index)
{
if(index>end)
{
while(!int_q1.isempty())
	{
	 int temp=int_q1.dequeue();
	}
return;
}
else
{

int_q1.display();

cout<<s[index];
cout<<endl;
int_q1.enqueue(s[index]);
if(start<=end)
{
cout<<"start="<<start;
print(s,set_size,start,end,index+1);
start=start+1;
index=start;
if(index<=end&&start<=end)
{
cout<<"entered";
print(s,set_size,start,end,index);
}
}
return;
}
}
