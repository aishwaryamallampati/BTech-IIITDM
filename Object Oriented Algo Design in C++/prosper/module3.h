#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class module3
{
	public:
		void quick_insertion_sort(int a[100],int size);
		void initialization();
		void display(int array[1000],int size);
		int array[500];
		int size;
		int k;
		void quick(int[],int ,int );
		void swap(int *a,int *b);
		int partition(int a[100],int p,int r);
		void merge_insertion_sort(int array[1000],int size);
		void mergesort(int array[100],int p,int r);
		void merge(int array[100],int p,int q,int r);
		int search(int a[100],int size,int k);
		void varsearch(int array[1000],int size,int k);
};
		
