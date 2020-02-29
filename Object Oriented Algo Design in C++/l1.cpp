#include<iostream>
#include<math.h>
using namespace std;

class steps
{
	public:
		steps();
		int size;//size here refers to the number of steps in the ladder
		int fib(int size);
		void allcombination(int arr[],int arr_size,int string_size);
		void allcombrecur(int arr[],int data[],int data_last,int data_index,int arr_size);
		

};
static int l=0,count=0;
static int b[1000]={0};
static int p=0;
//int power1;
steps::steps()
{
	int result;
	cout<<"\nenter the number of steps:";
	cin>>size;
	result=fib(size);
	//power1=pow(3,size);
	//cout<<power1<<endl;
	int arr[]={0,1,2};
	cout<<"\nall permutations with repetitions of the given no of steps: \n";
	allcombination(arr,3,size-1);
	cout<<"the total number of possibilities is(check): "<<count<<endl;
}

void steps::allcombination(int arr[],int arr_size,int string_size)
{
	int data[string_size+1];
	allcombrecur(arr,data,(string_size),0,arr_size);
}

void steps::allcombrecur(int arr[],int data[],int data_last,int data_index,int arr_size)
{
	int i,j,sum,k=0,m=0,duplicate=0,n;
	int a[1000]={0};
	
	for(i=0;i<arr_size;i++)
	{
	 data[data_index]=arr[i];
	 if(data_index==data_last)
	 {
	       
		sum=0;
	  
	  {
	  for(j=0;j<=data_last;j++)
		sum=sum+data[j];
	  if(sum==(data_last+1))
	  {	
		//cout<<"\ndata:";
	   for(j=0;j<=data_last;j++)
	   {
		if(data[j]!=0)
		{
	         //cout<<data[j]<<" ";
		 a[k]=data[j];
		 k++;
		}
			
	   }	
	   //cout<<endl;
	   for(n=0;n<k;n++)
	   {
		b[l]=b[l]+a[n]*(10^n);
	   }
	   l++;	
	   while((duplicate==0)&&(m<l-1))
	   {	
	        
		if(b[l-1]==b[m])
		 duplicate=1;
	    	m++;
	   }
	   
	   if(duplicate==0)
	   {
	    for(j=0;j<k;j++)
	     {
		cout<<a[j]<<" ";
	     }
	    count++;
	    cout<<endl;
	   }
	  }
	 }
	 }
	 
	 else
	 {
	  //cout<<"entered"<<data_index+1<<endl;
	  allcombrecur(arr,data,data_last,data_index+1,arr_size);
	 }
	
	}
}
int steps::fib(int n)
{
	int f,f1,f2,i;
	if(n<=1)
	  return n;
	else
	{
	 f2=0;
	 f1=1;
 	 for(i=2;i<n;i++)
	 {
		f=f1+f2;
		f2=f1;
		f1=f;
	 }
	}
	return f;
}

main()
{		
	double total_time;
	clock_t start,end;
	start=clock();
	steps steps1;
	cout<<"the total number of possibilities is "<<count<<endl;
	end=clock();
	
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for calculating no of posiibilites for given no of steps:"<<total_time<<endl;
	return 0;
}
