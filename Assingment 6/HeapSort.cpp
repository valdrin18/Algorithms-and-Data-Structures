#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

/* 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    In this cpp file I have included both
    The HeapSort and The HeapSortVariant.
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

//The algorithm part
void Heap(int arr[], int n, int i){
   
   int l=i;
   int left=(2*i+1),right=(2*i+2);

   if(left<n && arr[left] > arr[l]){
      l=left;
   }
   if(right<n && arr[right]>arr[l]){
      l=right;
   }
   if(l != i){
      int x = arr[i];
      arr[i] = arr[l];
      arr[l] = x;
      Heap(arr,n,l);
   }
}

//algorithm in the new variant
void variant(int arr[], int i, int n){

   int left=(2*i+1),right=(2*i+2),l=0;

   if(left < n && arr[left] > arr[l]){
        l = left;
   }
   if(right < n && arr[right] > arr[l]){
        l = right;
   }
   if(l == 0){
        swap(arr[0], arr[i]);
        return;
    }
    variant(arr, l,n);
    swap(arr[0], arr[i]);
}

//build a max heap
void Max(int arr[],int n){
   for(int i = n/2; i>=0; i--){
      Heap(arr,n,i);
   }
}

//sorting part
void HeapSort(int arr[],int n){
   Max(arr,n);
   for(int i=n-1; i>0; i--){

      int x = arr[0];
      arr[0] = arr[i];
      arr[i] = x;
      n=n-1;
      Heap(arr,i,0);
   }
}

//sorting part with new variant
void HeapSortVariant(int arr[],int n){
   Max(arr,n);
   for(int i=n-1; i>0; i--){

      int x = arr[0];
      arr[0] = arr[i];
      arr[i] = x;
      n=n-1;
      variant(arr,0,n);
   }
}

int main(){
   
   //implementation and testing of both variants
    int arr1[] = { 4, 3, 1, 2, 6, 5 };
    int arr2[] = { 4, 3, 1, 2, 6, 5 };

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    HeapSort(arr1, n);
    HeapSortVariant(arr2, m);

    cout << "Sorted array by HeapSort is"<<endl;
    for (int i = 0; i < n; ++i){
        cout << arr1[i] << " ";
    }
    cout<<endl;

    cout << "Sorted array by HeapSortVariant is"<<endl;
    for (int i = 0; i < n; ++i){
        cout << arr2[i] << " ";
    }
    cout<<endl;
    
    //Now for different secuences
    ofstream f;
    f.open("A.txt");
    srand(time(NULL));
    clock_t start,stop;

    for(int r=0; r<=10000; r=r+10){

      int a1[r],a2[r];

      for(int i=0; i<r; i++){
          a1[i]=(rand()%10000)+1;
          a2[i]=(rand()%10000)+1;
      }

      start=clock();
      HeapSort(a1,r);
      stop=clock();
      double t1 =(double) (stop-start)/CLOCKS_PER_SEC;

      start=clock();
      HeapSort(a2,r);
      stop=clock();
      double t2 =(double) (stop-start)/CLOCKS_PER_SEC;

      f<<r<<" "<<t1<<" "<<t2<<endl;
    }
    f.close();
    return 0;
}

