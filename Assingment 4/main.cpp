#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
 
    int i = 0;

    int j = 0;

    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

void insertionSort(int arr[], int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        int key = arr[j];
        int i = j - 1;
        // Search for the position where to place key value in the sorted
        // subarray arr[0..i]
        while (i > p - 1 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void mergeSort(int arr[], int p, int r, int k) {
    if (r - p + 1 <= k) {
        // Sort using Insertion Sort
        insertionSort(arr, p, r);
    } else {
        // Sort using Merge Sort
        // Calculate middle position of the array
        int q = (p + r - 1) / 2;
        // Recursively call Merge Sort on the subarray left to middle position
        mergeSort(arr, p, q, k);
        // Recursively call Merge Sort on the subarray right to middle position
        mergeSort(arr, q + 1, r, k);
        // Merge both sorted subarrays into one sorted subarray
        merge(arr, p, q, r);
    }
}

int main()
{
    ofstream f;
    f.open("A.txt");
    int l=100000;

    //other examples now follow
    //here we have to measure by time in order to check
    //how long it takes for the sort to happen also depending
    //on different, best, average and worst cases

    clock_t start,stop;
    //take a couple of array instances

    //random array instance
    for(int k=10; k<1000; k=k+10){

        int i,arr[l];
        srand(time(NULL));
        for(i=0; i<l; i++){
            arr[i]=(rand()%100)+1;
        }
        start=clock();
        mergeSort(arr, 0, l- 1, k);
        stop=clock();

        double randtime =(double) (stop-start)/CLOCKS_PER_SEC;


        //best array instance
        int bestarr[l];
        for(i=0; i<l; i++){
            bestarr[i]=i+1;
        }
        start=clock();
        mergeSort(bestarr, 0, l- 1, k);
        stop=clock();
        double bestime=(double)(stop-start)/CLOCKS_PER_SEC;


        //worst array instance
        int worstarr[l];
        for(i=l; i>=0; i--){
            worstarr[l-i]=i+1;
        }
        start=clock();
        mergeSort(worstarr, 0, l- 1, k);
        stop=clock();
        double worstime=(double)(stop-start)/CLOCKS_PER_SEC;


        f<<k<<" "<<randtime<<" "<<bestime<<" "<<worstime<<endl;
    }
    f.close();
    return 0;
}
