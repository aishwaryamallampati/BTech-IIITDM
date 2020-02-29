
#include<iostream>
#include<string>
using namespace std;

int size;

static int count=0;

class knap_sack
{
	public:
		knap_sack(int W,int weight[100],int profit[100]=0,int flag=0);
		knap_sack(double W,double weight[100],double profit[100]=0,int flag=0);

		int pick[100][100];//to find the elements in picked
		int find_profit(int W,int weight[100],int profit[100]);
		void printpicks(int item,int W, int weight[100]);

		void allcombination(int arr[],int arr_size,int string_size,double W,double weight[100],double profit[100]);
		void allcombrecur(int arr[],int data[],int last,int index,int str_size,double W,double weight[100],double profit[100]);
		double prof[100];
		//void fractional_knapsack(int W,int weight[100],int profit[100]=0);
};

knap_sack::knap_sack(double W,double weight[100],double profit[100],int flag)
{
	int arr[]={0,1};  
	cout<<"\nall permutations with repetitions of the given array:\n";
	allcombination(arr,2,size,W,weight,profit);
	cout<<"total no of permutations is "<<count;
}

void knap_sack::allcombination(int arr[],int arr_size,int string_size,double W,double weight[100],double profit[100])
{
	int data[string_size-1];
	allcombrecur(arr,data,string_size-1,0,arr_size,W,weight,profit);
}

void knap_sack:: allcombrecur(int arr[],int data[],int data_last,int data_index,int arr_size,double W,double weight[100],double profit[100])
{
	int i,j,sum;
	
	for(i=0;i<arr_size;i++)
	{
	 data[data_index]=arr[i];
	 if(data_index==data_last)
	 {
		sum=0;
	  for(j=0;j<=data_last;j++)
		sum=sum+data[j]*weight[j];
	  if(sum<=W)
	  {	
	   for(j=0;j<=data_last;j++)
	   {
		cout<<data[j]<<" ";
		prof[i]=prof[i]+data[j]*profit[j];
	   }
	   cout<<endl;
	   count++;
	  }
	 }
	 else
	  allcombrecur(arr,data,data_last,data_index+1,arr_size,W,weight,profit);
	}
}

main()
{ 
	{		
	 double W;
	 int size;
	 cout<<"\nenter the capacity of the sack:";
	 cin>>W;
	 cout<<"\nenter the number of items in the sack:";
	 cin>>size;
	 double weight[size],profit[size];	
	for(int i=0;i<size;i++)
	{
        	 cout<<"\nenter the weight of "<<i<<" element:";
		 cin>>weight[i];
		 cout<<"\nenter the value of "<<i<<" element:";
		 cin>>profit[i];
	}
	knap_sack sack1(W,weight,profit);
	}
	return 0;		
}
