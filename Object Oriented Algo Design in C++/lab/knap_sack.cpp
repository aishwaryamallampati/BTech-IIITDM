/*given n objects with their weights and values, objective is to maximise profit by including objects into a sack of fixed capacity*/
#include<iostream>
using namespace std;
int size;
int n;

double max_profit=0;
int max_array[100]={0};


class knap_sack
{
	public:
		knap_sack(int W,int weight[100],int profit[100]=0,int flag=0);
		knap_sack(double W,double weight[100],double profit[100]=0,int flag=0);

		int pick[100][100];//to find the elements in picked
		int find_profit(int W,int weight[100],int profit[100]);
		void printpicks(int item,int W, int weight[100]);

		void ladder_path(int size,double W,double weight[100],double profit[100]);
		void print_ladder_path(int data[],int i,int size,double W,double weight[100],double profit[100]);
		//void fractional_knapsack(int W,int weight[100],int profit[100]=0);
};

//original kanp sack with integer inputs
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
//knap sack with double values as inputs
knap_sack::knap_sack(double W,double weight[100],double profit[100],int flag)
{
	if(flag==1)
	{
	int used[100]={0},curw,maxi=1,totalprofit=0,temp;
	double ratio[100];
	curw=W;
	for(int i=1;i<=size;i++)
	{
	 	ratio[i]=profit[i]/weight[i];
		//cout<<ratio[i]<<" ";
	}
	for(int i=1;i<=size;i++)
	{
	 for(int j=i+1;j<=size;j++)
	 {
	  if(ratio[i]<ratio[j])
	  {
	    	temp=ratio[i];
		ratio[i]=ratio[j];
		ratio[j]=temp;
	
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
	  cout<<"\nadded object "<<l<<" weight="<<weight[l]<<" profit="<<profit[l]<<" completely in the bag. space left="<<curw<<endl;
	 }
	 else
	 {
	  cout<<"\nadded object "<<l<<" weight="<<(weight[l]+curw)<<" profit="<<(profit[l]/weight[l])*(weight[l]+curw)<<" partially in the bag. space left="<<0<<endl;
	  totalprofit=totalprofit-profit[l];
	  totalprofit=totalprofit+((profit[l]/weight[l])*(weight[l]+curw));
	 }
	 l++;
	}
	cout<<"bags filled with worth "<<totalprofit<<endl;
	}
	else
	{
	 int arr[]={0,1};  
	 cout<<"\nall permutations with repetitions of the given array:\n";
	 ladder_path(size,W,weight,profit);
	}
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
		//count_steps++;
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
	int key,value,result;
	
	int option;
	
	do
	 {
	    cout<<"\n1.knap sack with integer inputs\n2.knap sack with double values as inputs\n3.knap sack without profits but |s| must be maximum \n4.fractional knap sack\nenter your choice:";
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
			knap_sack sack1(W,weight,profit);
			}
			 break;
		  case 2: 
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
			 break;
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
			knap_sack sack1(W,weight,profit);
			}
			 break;
		case 4: 
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
			knap_sack sack1(W,weight,profit,1);
			}
			 break;
		  
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
