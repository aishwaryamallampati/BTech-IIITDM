#include<stdio.h>

void allcombination(int arr[],int arr_size,int string_size);
void allcombrecur(int arr[],int data[],int last,int index,int size);
static int count=0;

int main()
{
 	int arr[]={0,1,2};
	   
	printf("\nall permutations with repetitions of the given array: \n");
	allcombination(arr,3,4);
	printf("total no of permutations is %d\n",count);
	return 0;
}

void allcombination(int arr[],int arr_size,int string_size)
{
	int data[string_size-1];
	allcombrecur(arr,data,string_size-1,0,arr_size);
}

void allcombrecur(int arr[],int data[],int data_last,int data_index,int arr_size)
{
	int i,j;
	for(i=0;i<arr_size;i++)
	{
	 data[data_index]=arr[i];
	 if(data_index==data_last)
	 {
	  for(j=0;j<=data_last;j++)
		printf("%d",data[j]);
	  printf("\n");
	  count++;
	 }
	 else
	  allcombrecur(arr,data,data_last,data_index+1,arr_size);
	}
}
