#include<stdio.h>

void combination(int arr[],int data[],int start,int end,int index,int r);
void printcombination(int arr[],int  n,int r);

void combination(int arr[],int data[],int start,int end,int index,int r)
{
	int i,j;	
	if(index==r)
	{
	 for(j=0;j<r;j++)
		printf("%d",data[j]);
	 printf("\n");
	 return;
	}
	for(i=start;i<=end&&end-i+1>=r-index;i++)
	{
	 data[index]=arr[i];
	 combination(arr,data,i+1,end,index+1,r);
	}
}

void printcombination(int arr[],int  n,int r)
{
	int data[r];
	combination(arr,data,0,n-1,0,r);
}

int main()
{
	int arr[]={1,2,3,4,5};
	int r=6;
	int n=5;
	printcombination(arr,n,r);
}
