#include <stdio.h> 
#include <time.h> 
// this can be used to get run time of a function in c 

int fun(int theArray[], int n){ 
//function
    int max_ind = 0;
    for (int i = 1; i < n; i++)
        if ( theArray[ i ] >= theArray[ max_ind ] )
            max_ind = i;
    return max_ind;
}

// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
    int array[] = {1,2,3,4,5,6,7,8,9,10};
   // Calculate the time taken by fun() 
   clock_t t; 
   t = clock(); 
   int res = fun(array, 10); 
   t = clock() - t; 
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
   printf("fun() took %f seconds to execute \n", time_taken); 
   return 0; 
}