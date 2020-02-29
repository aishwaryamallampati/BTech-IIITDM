/*given n objects with their weights and values, objective is to maximise profit by including objects into a sack of fixed capacity*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int size;
int n;

double max_profit=0;
int max_array[100]={0};


class knap_sack
{
	public:
		knap_sack(int W,int weight[100],int profit[100]=0);
		

		//to find the elements in picked
		int find_profit(int W,int weight[100],int profit[100]);
		//void printpicks(int item,int W, int weight[100],int profit[100],int pick[][]);
};

//original kanp sack with integer inputs
knap_sack::knap_sack(int W,int weight[100],int profit[100])
{
	// pick[100][100]={0};
		
	 cout<<"the picks using dp are: ";
	 int p=find_profit(W,weight,profit);
	 
	 
	 cout<<"\nthe maximum profit using dp is "<<p<<endl;
	 cout<<endl;
}


int knap_sack::find_profit(int W,int weight[100],int profit[100])
{
	int w,i,curw;
	int m[size+1][W+1];
	int pick[size+1][W+1];
	curw=W;
	
	for(w=0;w<=W+1;w++)
	{
	  	m[0][w]=0;
		pick[0][w]=0;
	}
	for(i=1;i<=size;i++)
	{
	 for(w=0;w<=W;w++)
	 {
	   /*if(i==1)
	   {
	 	if(weight[1]<=W)
		{
		 pick[i][W]=1;
		 m[i][W]=profit[i];
		}
		else
		{
		 pick[i][W]=-1;
		 m[i][W]=0;
		}
	   }*/
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
	//printpicks(size,W,weight,profit,pick);
	 //cout<<endl;
	//cout<<"entered"<<endl;
	for(int item=size;item>0;item--)
	{
	 //cout<<"pick="<<pick[item][W]<<endl;
	 if(pick[item][curw]==1)
	 {
		cout<<"("<<weight[item]<<","<<profit[item]<<")"<<" ";
		//cout<<"enter";
		//cout<<item<<" ";
		curw=curw-weight[item];
	 }
	}
	
	return m[size][W];
} //returns maximum profit value


/*void knap_sack::printpicks(int size, int W,int weight[100],int profit[100],int pick[][])
{
	cout<<"entered"<<endl;
	for(int item=size;item>0;item--)
	{
	 cout<<"pick="<<pick[item][W]<<endl;
	 if(pick[item][W]==1)
	 {
		//cout<<"("<<weight[item]<<","<<profit[item]<<")"<<" ";
		cout<<"enter";
		cout<<item<<" ";
		W=W-weight[item];
	 }
	
	}
}*///prints the items that has to be picked

/*
class greedy_knap
{
	public:
	greedy_knap(int W,int weight[100],int profit[100]);
};

greedy_knap::greedy_knap(int W,int weight[100],int profit[100])
{
	int temp,curw,totalprofit=0;
	curw=W;
	for(int i=1;i<=size;i++)
	{
	 for(int j=i+1;j<=size;j++)
	 {
	  if(weight[i]>weight[j])
	  {
		temp=weight[i];
		weight[i]=weight[j];
		weight[j]=temp;
		
		temp=profit[i];
		profit[i]=profit[j];
		profit[j]=temp;
	  }
	 }
	}
	int l=1;
	while(curw>=0&&l<=size)
	{
	 
	 //cout<<"maxi="<<maxi;
	 curw=curw-weight[l];
	 totalprofit=totalprofit+profit[l];
	 if(curw>=0)
	 {
	  cout<<"("<<weight[l]<<","<<profit[l]<<")"<<" ";
	 }
	l++;
	}
	cout<<endl;
	cout<<"the maximum profit using greedy is "<<totalprofit<<endl;
}*/

main()
{	
	int key,value,result;
	int option;
			 int W;
			 W=100;
			 size=10;
			 
			 int weight[size],profit[size];	
			for(int j=1;j<=50;j++)
			{
			 cout<<"for "<<j<<" input :"<<endl;
			 
			 //weight[size]={0};
			 //profit[size]={0};
			for(int i=1;i<=size;i++)
			{
        		 weight[i]=(rand()%51)+1;
			 profit[i]=(rand()%51)+1;
			 cout<<"("<<weight[i]<<","<<profit[i]<<")"<<" ";
			}
			cout<<endl;
			knap_sack sack1(W,weight,profit);
			//cout<<"the picks using greedy are:";
			//greedy_knap sack2(W,weight,profit);
			}
			 
		
	return 0;
}


	
	 

