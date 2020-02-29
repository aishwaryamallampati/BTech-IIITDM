#include<stdio.h>

int main()
{
 	int arr[]={0,1,2}
	printf("\nall permutations with repetitions of the given array: \n")
	allcombination(arr,3,2);
	return 0;
}

void allcombination(int arr[],int size,int r)
{
	int data[r];
	allcombrecur(arr,data,r-1,0,int size);
}

void allcombrecur(int arr[],int data[],int last,int index,int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
	 data[index]=arr[i];
	 if(index==last)
	 {
	  for(j=0;j<=last;j++)
		printf("%d",data[j]);
	  printf("\n");
	  return;
	 }
	 else
	  allcombrecur(arr,data,last,index+1,size);
	}
}
