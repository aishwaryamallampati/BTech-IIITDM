#include<iostream>
#include<string>
using namespace std;
int n;
int size;
double max_profit=0;
int max_array[100]={0};

static int count_steps=0;

class knap_sack
{
	public:
		
		knap_sack(double W,double weight[100],double profit[100]=0,int flag=0);
		void ladder_path(int size,double W,double weight[100],double profit[100]);
		void print_ladder_path(int data[],int i,int size,double W,double weight[100],double profit[100]);
};

knap_sack::knap_sack(double W,double weight[100],double profit[100],int flag)
{
	int arr[]={0,1};  
	cout<<"\nall permutations with repetitions of the given array:\n";
	ladder_path(size,W,weight,profit);
	
}

void knap_sack::ladder_path(int size,double W,double weight[100],double profit[100])
    {
    	// since maximum length of string can be n
        int data[size+1];
     
        print_ladder_path(data,0,size,W,weight,profit);
    }

 void knap_sack::print_ladder_path(int data[],int i,int size,double W,double weight[100],double profit[100])
    {
    	// Base case 1
        if(size<0)
            return;
     
        // Base case 2, If n becomes 0, just print the answer
        if(size==0)
        {
	   int j=0;
	    double sum=0;
	    double p=0;
	    data[i]='\0';
            //cout<<"enter"<<endl;
            while(j<n)
	    {
		//cout<<"entered"<<endl;
		if(data[j]==1)
		{
		 //cout<<"weight[j]="<<weight[j];
	    	 sum=sum+weight[j];
		//cout<<sum;
		 p=p+profit[j];
		}
		j++;
	    }
		
		//cout<<p<<" ";
		//cout<<"sum="<<sum<<endl;
		if(sum<=W)
		{
		 
		 if(p>=max_profit)
		 {
		  cout<<"entered";
		 max_profit=p;
		 for(int r=0;r<n;r++)
	         {
	    	  max_array[r]=data[r];
		  cout<<data[r]<<" ";
	         }
		 }
		
		cout<<endl;
		count_steps++;
		}
	    
            return;
        }
        // You can either put 1 and decrement n by 1
        data[i]=1;
        print_ladder_path(data,i+1,size-1,W,weight,profit);
  
        // Or you can put 0 and decrement n by 1
	 data[i]=0;
        print_ladder_path(data,i+1,size-1,W,weight,profit);
   }

main()
{ 
	{		
	 double W;
	 
	 cout<<"\nenter the capacity of the sack:";
	 cin>>W;
	 cout<<"\nenter the number of items in the sack:";
	 cin>>size;
	 n=size;
	 double weight[size],profit[size];	
	for(int i=0;i<size;i++)
	{
        	 cout<<"\nenter the weight of "<<i<<" element:";
		 cin>>weight[i];
		 cout<<"\nenter the value of "<<i<<" element:";
		 cin>>profit[i];
	}
	knap_sack sack1(W,weight,profit);
	cout<<"the picks are:"<<endl;
	for(int j=0;j<n;j++)
	cout<<max_array[j]<<" ";
	cout<<endl;
	cout<<"the maximum profit is "<<max_profit<<endl;
	}
	return 0;		
}

