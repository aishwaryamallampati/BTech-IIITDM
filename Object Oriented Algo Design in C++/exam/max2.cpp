/*given an array find max mand min using 2 way divide and conquer*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int max1,min1;



class array
{
public:
	array();

	int a[1000];
	int size;
};

array::array()
{
	int index1;
	size=100;
	cout<<"\nthe given array:";
	for(index1=1;index1<=size;index1++)
	{
	 a[index1]=rand()%3000;
	 cout<<a[index1]<<" ";
	}
	cout<<endl;
}

class maxmin
{
	public:
		maxmin();
		

		void find(int array[1000],int start,int end);
};

maxmin::maxmin()
{
	array array1;
	max1=array1.a[1];
	min1=array1.a[1];
	find(array1.a,1,array1.size);
	cout<<"\nmax="<<max1;
	cout<<"\nmin="<<min1;
}

void maxmin::find(int array[100],int start,int end)
{
	if(start==end)
	{
	 if(max1<array[start])
		max1=array[start];
	 if(min1>array[start])
		min1=array[start];
	}
	else if(start<end)
	{
	 
	 int mid=(start+end)/2;
	 if(mid<start)
	 {
		mid=start;
	  find(array,start,mid);
	 }
	 else
	 find(array,start,mid);
	 
	 find(array,mid+1,end);
	
	}
}

main()
{
	double total_time,sum=0,average;
	clock_t start,end;
	
	int index1,index2;
	double time[100];
	
	for(index1=1;index1<=100;index1++)
	{
	 start=clock();
	 cout<<"\nfor array "<<index1<<":"<<endl;
	 
	 maxmin maxmin1;
	 end=clock();
	 
	 total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	 cout<<"\ntime taken for 2 way find max min:"<<total_time<<endl;
	 time[index1]=total_time;
	}//repeatedly create 100 random arrays and sort them
	for(index1=1;index1<=100;index1++)
	{
	 sum=sum+time[index1];
	}
	average=sum/100;//to calculate average time for 100 arrays of same size
	cout<<"\naverage time taken for 2 way find max min: "<<average<<endl;
	return 0;
}

