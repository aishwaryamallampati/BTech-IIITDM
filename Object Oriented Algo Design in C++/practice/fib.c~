#include<stdio.h>

int main()
{
	int n,i=0,c;
	int result;
	printf("\nenter the number of steps: ");
	scanf("%d",&n);
	
	result=fib(n);
	printf(" %d",result);
	return 0;
}

int fib(int n)
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
