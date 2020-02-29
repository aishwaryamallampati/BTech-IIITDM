#include<iostream>
using namespace std;



class array_create
{
public:
	array_create();

	int a[1000];
	int size;
};

array_create::array_create()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>a[index1];
}

class distinct_heap
{
	public:
	distinct_heap();
	int distinct[1000];
	int repetition[1000];
	int find(int array[1000],int size,int key);
	void display(int array[1000],int size);

	int array[1000];
	int size;
	void heapify();
	void build_minheap();
	void min_heapify(int size,int i);
	void heapsort();
	void display_rep(int array[1000],int size);
};

distinct_heap::distinct_heap()
{
	array_create array1;
	int k,dup;
	k=2;
	distinct[1]=array1.a[1];
	repetition[1]=1;
	for(int i=2;i<=array1.size;i++)
	{
	 dup=find(distinct,k-1,array1.a[i]);
	 if(dup!=0)
	   	repetition[dup]=repetition[dup]+1;
	 else
	 {
	  distinct[k]=array1.a[i];
	  repetition[k]=1;
	  k++;
	 }
	}
	cout<<"\nthe distinct array:"<<endl;
	display(distinct,k-1);
	cout<<"\nthe repetition array:"<<endl;
	display(repetition,k-1);
	size=k-1;
	for(int i=1;i<=size;i++)
		array[i]=distinct[i];
	//cout<<"the array:"<<endl;
	//for(int i=1;i<=size;i++)
		//cout<<array[i]<<" ";
	//cout<<endl;
	heapify();
	cout<<"the final sorted array is:"<<endl;
	display_rep(array,size);	
}

int distinct_heap::find(int array[1000],int size,int key)
{
	for(int i=1;i<=size;i++)
	{
	 if(array[i]==key)
	 return i;
	}
	return 0;
}

void distinct_heap::heapify()
{
	build_minheap();
	heapsort();
	cout<<"\nthe heap array:"<<endl;
	 display(array,size);
	 display(repetition,size);
}

void distinct_heap::build_minheap()
{
	for(int i=size/2;i>=1;i--)
	 min_heapify(size,i);
	return;
}

void distinct_heap::min_heapify(int size,int i)
{
	int j,temp,temp1;
	
	temp=array[i];
	temp1=repetition[i];
	j=2*i;
	while(j<=size)
	{
	  if(j<size && array[j+1]>array[j])
	   j=j+1;
	  if(temp>array[j])
           break;
	  else if(temp<=array[j])
	  {
	   array[j/2]=array[j];
	   repetition[j/2]=repetition[j];
	   j=2*j;
	  }
	}
	array[j/2]=temp;
	repetition[j/2]=temp1;
	return;
}

void distinct_heap::heapsort()
{
	int i,temp,temp1;
	for(i=size;i>=2;i--)
	{
		temp=array[i];
			temp1=repetition[i];
		array[i]=array[1];
			repetition[i]=repetition[1];
		array[1]=temp;
			repetition[1]=temp1;
		min_heapify(i-1,1);
	}
}

void distinct_heap::display(int array[1000],int size)
{
	if(size<1)
	cout<<"the array is empty"<<endl;
	else
	{	
	 for(int i=1;i<=size;i++)
	  cout<<array[i]<<" ";
	 cout<<endl;
	}
}

void distinct_heap::display_rep(int array[1000],int size)
{
	if(size<1)
	cout<<"the array is empty"<<endl;
	else
	{	
	 for(int i=1;i<=size;i++)
	 {
	  if(repetition[i]==1)
	  cout<<array[i]<<" ";
	  else
	  {
	   int count=repetition[i];
	   while(count>=1)
	   {
		cout<<array[i]<<" ";
		count--;
	   }
	  }
	 }
	 cout<<endl;
	}
}

main()
{
 	distinct_heap heap1;
	
}


