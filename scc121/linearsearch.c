#include <stdlib.h>

int linearSearch(int theArray[], int n, int val){
    for (int i = 0; i < n; i++){
        if (theArray[i] == val){
            return i;
        }
    }
    return -1;
}

int main(){

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int i = linearSearch(array, 10, 5);

    return 0;
}