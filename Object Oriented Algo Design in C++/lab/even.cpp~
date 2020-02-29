/*given an array cont the number of even numbers using divide and conquer*/
#include<iostream>
using namespace std;

static int count=0;
int used[1000]={0};

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
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>a[index1];
}

class even
{
	public:
		even();
		void divide(int array[1000],int start,int end);
		void merge(int array[1000],int p,int q,int r);
};

even::even()
{
	int pass,index1,hold;
	array array1;
	divide(array1.a,1,array1.size);
	cout<<"\nthe total number of even numbers in the given array is: "<<count;
	cout<<endl;
	
}

void even::divide(int array[1000],int p,int r)
{
	int q;	
	if(p<r)
	{
	 q=(p+r)/2;
	 divide(array,p,q);
	 divide(array,q+1,r);
	 merge(array,p,q,r);
	}
}
void even::merge(int a[1000],int p,int q,int r)
{
	int n1,n2,i,j,k;
	int l[500],ri[500];
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++)
		l[i]=a[p+i-1];

	/*cout<<"leftarray: ";
	for(i=1;i<=n1;i++)
		cout<<l[i]<<" ";
	cout<<endl;*/
	
	for(j=1;j<=n2;j++)
		ri[j]=a[q+j];

	/*cout<<"right array:";
	for(j=1;j<=n2;j++)
		cout<<ri[j]<<" ";
	cout<<endl;*/

	l[n1+1]=1000;
	ri[n2+1]=1000;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
	 if(used[k]!=1)
	 {
	  if(l[i]<=ri[j])
	  {
		a[k]=l[i];
		i=i+1;
		if(used[k]!=1)
		{
		 used[k]=1;
		 if(a[k]%2==0)
		 {
		  count++;
		 }
		}
	  
	  }
	  else
	  {
	   a[k]=ri[j];
	   j=j+1;
	   if(used[k]!=1)
	   {
		used[k]=1;
		 if(a[k]%2==0)
		 {
		  
		  count++;
		 
		  
		 }
	    }
	  } 
	 }
	}

	/*cout<<"array:";
	for(k=p;k<=r;k++)
	 cout<<a[k]<<" ";
	cout<<endl;*/
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	even even1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for bubble sort:"<<total_time<<endl;
	return 0;
}
