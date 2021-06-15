/* CH08-320211
 (lanuage-Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/
/*
     _____     _____    ^   ******
    |     |   |     |   |   |\   |
    |     |   |_____|   |   | \  |
    |     |   |\        |   |  \ |
    |_____|  _| \_      |   |   \|
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;


//Counting Sort algorithm
void CountSort(int array[], int size) {

  int output[10];
  int count[10];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

//Bucket Sort algorithm
void BucketSort(float arr[], int n){

    // 1) Create n empty buckets
    vector<float> b[n];
 
    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

//main function
int main(){

    //a). Implementation of Count Sort for the following array
    int arr1 [] = {9, 1, 6, 7, 6, 2, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    CountSort(arr1,n);
    cout<<endl<<"Sorted array by Count Sort algorithm:"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    
    cout<<endl;;

    //b). Implementation of Bucket Sort for the following array
    float arr2 [] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    BucketSort(arr2,m);
    cout<<"Sorted array by Bucket Sort algorithm:"<<endl;
    for(int i=0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl<<endl;
    return 0;
}