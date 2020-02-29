/*given n objects with their weights and values, objective is to maximise profit by including objects into a sack of fixed capacity*/
#include<iostream>
using namespace std;
int size;

template <class t>
class knap_sack
{
	public:
		knap_sack(t W,t weight[100],t profit[100]=0,int flag=0);
		
		
		t pick[100][100];//to find the elements in picked
		t find_profit(t W,t weight[100],t profit[100]);
		void printpicks(int item,t W, t weight[100]);
};

template <class t>
knap_sack<t>::knap_sack(t W,t weight[100],t profit[100],int flag)
{
	t p=find_profit(W,weight,profit);
	cout<<"the maximum profit is "<<p<<endl;
	cout<<"the picks are: ";
	printpicks(size,W,weight);
	cout<<endl;
}

template <class t>
t knap_sack<t>::find_profit(t W,t weight[100],t profit[100])
{
	int w,i;
	t m[size+1][W+1];
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

template <class t>
void knap_sack<t>::printpicks(int item, t W,t weight[100])
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
	
	int option;
	
	do
	 {
	    cout<<"\n1.knap sack with integer inputs\n2.knap sack with doubleing values as inputs\n3.knap sack without profits but |s| must be maximum \n4.fractional knap sack\nenter your choice:";
	    cin>>option;
	    switch(option)
		{
		  case 1: 
			{
			 int W;
			 cout<<"\nenter the capacity of the sack:";
			 cin>>W;
			 cout<<"\nenter the number of items in the sack:";
			 cin>>size;
			 int weight[size],profit[size];	
			for(int i=1;i<=size;i++)
			{
        		 cout<<"\nenter the weight of "<<i<<" element:";
			 cin>>weight[i];
			 cout<<"\nenter the value of "<<i<<" element:";
			 cin>>profit[i];
			}
			knap_sack<int> int_sack1(W,weight,profit);
			}
			 break;
		  /*case 2: 
			{
			 double W;
			 cout<<"\nenter the capacity of the sack:";
			 cin>>W;
			 cout<<"\nenter the number of items in the sack:";
			 cin>>size;
			 double weight[size],profit[size];	
			for(int i=1;i<=size;i++)
			{
        		 cout<<"\nenter the weight of "<<i<<" element:";
			 cin>>weight[i];
			 cout<<"\nenter the value of "<<i<<" element:";
			 cin>>profit[i];
			}
			knap_sack<double> double_sack1(W,weight,profit);
			}
			 break;*/
		  case 3: 
			{
			 int W;
			 int weight[size],profit[size];	
			 cout<<"\nenter the capacity of the sack:";
			 cin>>W;
			 cout<<"\nenter the number of items in the sack:";
			 cin>>size;
			for(int i=1;i<=size;i++)
			{
        		 cout<<"\nenter the weight of "<<i<<" element:";
			 cin>>weight[i];
			 profit[i]=1;
			}
			knap_sack<int> int_sack1(W,weight,profit);
			}
			 break;
		  
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
