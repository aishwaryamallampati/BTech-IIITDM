#include <iostream>
#include<math.h>
using namespace std;

class heap
{
public:
	heap();
	int a[1000];
	int size;
	int result;
	int count;
	//void heapify();
	//void build_minheap();
	//void max_heapify(int size,int i);
	//void heapsort();
	void display();
	void get_maxmin();
	void extract_min();
	void extract_max();

	void trickledown(int size,int i);
	void trickledownmin(int size,int i);
	int max1(int size,int i);
	int min1(int size,int i);
	int find(int size,int i,int result);
	void trickledownmax(int size,int i);
	int insertion(int array[1000],int start,int end);
	int insertion1(int array[1000],int start,int end);
	void bubbleup(int i);
	void bubbleupmin(int i);
	void bubbleupmax(int i);
};

heap::heap()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	{
	 cin>>a[index1];
	 bubbleup(index1);
	// trickledown(index1,index1);
	}
	//heapify();
	cout<<"the min max heap is:"<<endl;
	display();
}





void heap::trickledown(int size,int i)
{
	int l=log2(i);	
	if(((l+1)%2)==1)
	 trickledownmin(size,i);
	else
	 trickledownmax(size,i);
}

void heap::trickledownmin(int size,int i)
{
	int l,r,m,temp;
	l=2*i;
	r=2*i+1;
	if(l<=size || r<=size)
	{
	m=min1(size,i);
	if((m/(2*i))!=0  && (m/(2*i))!=1)
	{
	 if(a[m]<a[i])
	 {
	  temp=a[m];
	  a[m]=a[i];
  	  a[i]=temp;
	  if(a[m]>a[m/2])
	  {
	   temp=a[m];
	   a[m]=a[m/2];
  	   a[m/2]=temp;	
	  } 
	  trickledownmin(size,m);
	 }
	}
	else
	{
	 if(a[m]<a[i])
	 {
	  temp=a[m];
	  a[m]=a[i];
  	  a[i]=temp;
	 }
	}
       }	
}

void heap::trickledownmax(int size,int i)
{
	int l,r,m,temp;
	l=2*i;
	r=2*i+1;
	if(l<=size || r<=size)
	{
	 m=max1(size,i);
	 
	 //cout<<"a[m]="<<a[m];
	if((m/(2*i))!=0  && (m/(2*i))!=1)
	{
	 if(a[m]>a[i])
	 {
	  temp=a[m];
	  a[m]=a[i];
  	  a[i]=temp;
	  if(a[m]<a[m/2])
	  {
	   temp=a[m];
	   a[m]=a[m/2];
  	   a[m/2]=temp;	
	  } 
	  trickledownmax(size,m);
	 }
	}
	else
	{
	 if(a[m]>a[i])
	 {
	  temp=a[m];
	  a[m]=a[i];
	  a[i]=temp;
	 }
	}
       }	
}

void heap::extract_min()
{
	if(size<=0)
	 cout<<"the heap is empty\n";
	else if(size==1)
	{
	 size=size-1;
	 cout<<"\nthe minimum  extracted is "<<a[1]<<endl;
	}
	else
	{
	 int root=a[1];
	 a[1]=a[size];
	 size=size-1;
         cout<<"\nthe minimum  extracted is "<<root<<endl;
	 //cout<<"input:";
	 //display();
	 trickledown(size,1);
	 //display();
	}
}

void heap::extract_max()
{
	if(size<=0)
	 cout<<"the heap is empty\n";
	else if(size==1)
	{
	 size=size-1;
	 cout<<"\nthe maximum  extracted is "<<a[1]<<endl;
	}
	else
	{
	 
	 if(a[2]<a[3])
	 {
	  cout<<"\nthe maximum  extracted  is "<<a[3]<<endl;
	  int root=a[3];
	  a[3]=a[size];
	  size=size-1;
	  trickledown(size,3);
	 }
	 else
	 {
	 cout<<"\nthe maximum  extracted is "<<a[2]<<endl;
	  int root=a[2];
	  a[2]=a[size];
	  size=size-1;
	  trickledown(size,2);
	 }
	 
	}
}


void heap::bubbleup(int i)
{
	int temp;
	int l=log2(i);	
	if(((l+1)%2)==1)
	{
	 if((i/2)>0 && a[i]>a[i/2])
	 {
	  temp=a[i/2];
	  a[i/2]=a[i];
  	  a[i]=temp;
	  bubbleupmax(i/2);
	 }
	 else
	  bubbleupmin(i);
	}
	else
	{
	 if((i/2)>0 && a[i]<a[i/2])
	 {
	  temp=a[i/2];
	  a[i/2]=a[i];
  	  a[i]=temp;
	  bubbleupmin(i/2);
	 }
	 else
	  bubbleupmax(i);
	}

}

void heap::bubbleupmin(int i)
{
	int temp;	
	if((i/4)>0)
	{
	 if(a[i]<a[i/4])
	 {
	  temp=a[i/4];
	  a[i/4]=a[i];
  	  a[i]=temp;
	  bubbleupmin(i/4);
	 }
	}
}


void heap::bubbleupmax(int i)
{
	int temp;	
	if((i/4)>0)
	{
	 if(a[i]>a[i/4])
	 {
	  temp=a[i/4];
	  a[i/4]=a[i];
  	  a[i]=temp;
	  bubbleupmax(i/4);
	 }
	}
}


int heap::max1(int size,int i)
{
	int arr[10];	
	int l,r,l1,l2,r1,r2;
	l=2*i;
	arr[1]=a[l];
	r=2*i+1;
	arr[2]=a[r];
	l1=2*l;
	arr[3]=a[l1];
	l2=2*l+1;
	arr[4]=a[l2];
	r1=2*r;
	arr[5]=a[r1];
	r2=2*r+1;
	arr[6]=a[r2];
	if(r>size)
	result=l;
	else if(l1>size)
	result=insertion1(arr,1,2);
	//for(int j=1;j<=2;j++)
	//cout<<" "<<arr[j]<<" ";}
	else if(l2>size)
	result=insertion1(arr,1,3);
	else if(r1>size)
	result=insertion1(arr,1,4);
	else if(r2>size)
	result=insertion1(arr,1,5);
	else 
	result=insertion1(arr,1,6);
	//cout<<"result="<<result;
	return find(size,i,result);
}

int heap::insertion(int array[1000],int start,int end)
  {
     int index1,index2,key;
     for(index1=start+1;index1<=end;index1++)
	{
	    key=array[index1];
	    index2=index1-1;
	    while(index2>0 && array[index2]>key)
		{
		    array[index2+1]=array[index2];
		    index2=index2-1;
	 	    count++;
		} 
	    array[index2+1]=key;
	}
	/*for(int index1=start;index1<=end;index1++)
        {
	   cout << "display";
	    cout << array[index1] << " ";
        }*/
	return array[1];
  }

int heap::insertion1(int array[1000],int start,int end)
  {
     int index1,index2,key;
     for(index1=start+1;index1<=end;index1++)
	{
	    key=array[index1];
	    index2=index1-1;
	    while(index2>0 && array[index2]>key)
		{
		    array[index2+1]=array[index2];
		    index2=index2-1;
	 	    count++;
		} 
	    array[index2+1]=key;
	}
	/*for(int index1=start;index1<=end;index1++)
        {
	   cout << "display";
	    cout << array[index1] << " ";
        }*/
	return array[end];
  }

int heap::min1(int size,int i)
{
	int l,r,l1,l2,r1,r2;
	int arr[10];
	l=2*i;
	arr[1]=a[l];
	r=2*i+1;
	arr[2]=a[r];
	l1=2*l;
	arr[3]=a[l1];
	l2=2*l+1;
	arr[4]=a[l2];
	r1=2*r;
	arr[5]=a[r1];
	r2=2*r+1;
	arr[6]=a[r2];
	if(r>size)
	result=l;
	else if(l1>size)
	result=insertion(arr,1,2);
	else if(l2>size)
	result=insertion(arr,1,3);
	else if(r1>size)
	result=insertion(arr,1,4);
	else if(r2>size)
	result=insertion(arr,1,5);
	else 
	result=insertion(arr,1,6);
	
	return find(size,i,result);
}


int heap::find(int size,int i,int result)
{
	int l,r,l1,l2,r1,r2;
	l=2*i;
	r=2*i+1;
	l1=2*l;
	l2=2*l+1;
	r1=2*r;
	r2=2*r+1;
	if(l<=size&&a[l]==result)
	return l;
	else if(r<=size&&a[r]==result)
	return r;
	else if(l1<=size&&a[l1]==result)
	return l1;
	else if(l2<=size&&a[l2]==result)
	return l2;
	else if(r1<=size&&a[r1]==result)
	return r1;
	else if(r2<=size&&a[r2]==result)
	return r2;
	
}


void heap::get_maxmin()
{
 	if(size<=1)
  	  return;
	else
	{
	 if(a[2]<a[3])
	 cout<<"\nthe maximum  of the given array is "<<a[3]<<endl;
	 else
	 cout<<"\nthe maximum  of the given array is "<<a[2]<<endl;
	 cout<<"\nthe minimum  of the given array is "<<a[1]<<endl;
	}
 
}	


void heap::display()
{
	if(size<1)
	cout<<"the array is empty"<<endl;
	else
	{	
	 for(int i=1;i<=size;i++)
	  cout<<a[i]<<" ";
	 cout<<endl;
	}
}

main()
{
	int option;
	heap heap1;
	do
	{
	 cout<<"1.get max min\n2.extract min\n3.extract max\nenter your choice:";
	 cin>>option;
	 switch(option)
	 {
	 case 1:
	  heap1.get_maxmin();
	  break;
	 case 2:
	  heap1.extract_min();
	  cout<<"the min max heap is:"<<endl;
	  heap1.display();
	  //heap1.heapify();
	  break;
	 case 3:
	  heap1.extract_max();
	  cout<<"the min max heap is:"<<endl;
	  heap1.display();
	  break;
	 case 0:
	  break;
	 }
	}while(option!=0);
	
	
}
