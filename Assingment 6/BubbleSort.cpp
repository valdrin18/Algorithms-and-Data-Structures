#include <iostream>
using namespace std;

//Implementation of bubble sort algorithm
void bubbleSort(int arr[], int n) 
{  
    //variables for the iteratation through elements
   int i, j; 
   //set this bool variable to check condition
   //whether there are swaps done or not
   //in order to break the loop is array is sorted already
   bool swapped; 
   //start the iteration
   for (i = 0; i < n-1; i++) 
   { 
     //as explained above
     swapped = false; 
     //inner loop iteration for swap checks
     for (j = 0; j < n-i-1; j++) 
     { 
        //if swap condition is fullfilled
        if (arr[j] > arr[j+1]) 
        { 
           //swap the elements and change state as true 
           //of the checking variable 
           int x = arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=x;
           swapped = true; 
        } 
     } 
     //If state not changed which means no swaps,then break 
     if (swapped == false) 
        break; 
   } 
} 

int main()
{
    //Testing and implementation
    int A[] = {5, 3, 1, 4, 6, 9, 2};  
    int n = sizeof(A)/sizeof(A[0]);  
    bubbleSort(A, n);  
    cout<<"Sorted array: \n";  
    for (int i = 0; i < n; i++){ 
        cout << A[i] << " ";  
    }
    return 0;
}

