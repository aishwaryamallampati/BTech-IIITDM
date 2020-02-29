//module1.h
# include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class module1
   {
      public:
	void insertion_sort_iterative(int[],int,int);
  	void insertion_sort_recursive(int[],int,int);
	void binary_insertion_sort(int array[100],int size);
	
	int bin_search(int[],int,int,int);
	void counting_inversions(int[],int,int);
	void initialization();
	void display(int[],int);
      //private:
	int count;
	int array[1000],size;
   };
