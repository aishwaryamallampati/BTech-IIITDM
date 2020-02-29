/*given n objects with their weights and values, objective is to maximise profit by including objects into a sack of fixed capacity*/
#include<iostream>
using namespace std;
int size;


class knap_sack
{
	public:
		knap_sack(int W,int weight[100],int profit[100]=0,int flag=0);
		
		
		int pick[100][100];//to find the elements in picked
		int find_profit(int W,int weight[100],int profit[100]);
		void printpicks(int item,int W, int weight[100]);
};

knap_sack::knap_sack(int W,int weight[100],int profit[100],int flag)
{
	int p=find_profit(W,weight,profit);
	cout<<"the maximum profit is "<<p<<endl;
	cout<<"the picks are: ";
	printpicks(size,W,weight);
	cout<<endl;
}

int knap_sack::find_profit(int W,int weight[100],int profit[100])
{
	int w,i;
	int m[size+1][W+1];
	for(w=0;w<=W+1;w++)
	  	m[0][w]=0;
	for(i=1;i<=size;i++)
	{
	 for(w=0;w<=W;w++)
	 {
	   if(w<weight[i])
	   {
		pick[i][w]=-1;
		m[i][w]=m[i-1][w];
	   }
	   else
	   {
		if((profit[i]+m[i-1][w-weight[i]])>m[i-1][w])
		{
	 		pick[i][w]=1;
			m[i][w]=profit[i]+m[i-1][w-weight[i]];
	        }
		else
		{
			pick[i][w]=-1;
			m[i][w]=m[i-1][w];
		}
	   }
	 }
	}
	return m[size][W];
} //returns maximum profit value

void knap_sack::printpicks(int item, int W,int weight[100])
{
	while(item>0)
	{
	 if(pick[item][W]==1)
	 {
		cout<<item<<" ";
		item--;
		W=W-weight[item];
	 }
	 else
		item--;
	}
}//prints the items that has to be picked

/*main()
{
	knap_sack sack1;
	return 0;
}*/

main()
{	
	int key,value,result;
	int W;
	int option;
	cout<<"\nenter the capacity of the sack:";
	cin>>W;
	cout<<"\nenter the number of items in the sack:";
	cin>>size;
	int weight[size],profit[size];	
	do
	 {
	    cout<<"\n1.knap sack with integer inputs\n2.knap sack with floating values as inputs\n3.knap sack without profits but |s| must be maximum \n4.fractional knap sack\nenter your choice:";
	    cin>>option;
	    switch(option)
		{
		  case 1: 
			{
			for(int i=1;i<=size;i++)
			{
        		 cout<<"\nenter the weight of "<<i<<" element:";
			 cin>>weight[i];
			 cout<<"\nenter the value of "<<i<<" element:";
			 cin>>profit[i];
			}
			knap_sack sack1(W,weight,profit);
			}
			 break;
		  /*case 2: 
			cout<<"\nenter key at which element are to be printed:";
			cin>>key;
			result=hash.get(key);
			cout<<result<<endl;
			 break;*/
		  case 3: 
			{
			for(int i=1;i<=size;i++)
			{
        		 cout<<"\nenter the weight of "<<i<<" element:";
			 cin>>weight[i];
			 profit[i]=1;
			}
			knap_sack sack1(W,weight,profit);
			}
			 break;
		  
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
