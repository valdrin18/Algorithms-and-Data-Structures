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


// Function to get maximum value
char Max(string arr[], int n){
    char max = arr[0].size();
    for (int i = 1; i < n; i++){
        if (arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}

// Counting Sort
void CountSort(string a[], int size, int k){

    string b[size];
    int c[127];

    for (int i = 0; i <127; i++){
        c[i] = 0;
    }
    for (int i = 0; i <size; i++){
        c[k < a[i].size() ? (int)(char)a[i][k] + 1 : 0]++;
    }
    for (int i = 1; i <127; i++){
        c[i] += c[i - 1];
    }
    for (int i = size - 1; i >= 0; i--){
        b[c[k < a[i].size() ? (int)(char)a[i][k] + 1 : 0] - 1] = a[i];
        c[k < a[i].size() ? (int)(char)a[i][k] + 1 : 0]--;
    }
    for (int i = 0; i < size; i++){
        a[i] = b[i];
    }
}

// Radix Sort
void RadixSort(string a[], int r){
    int max = Max(a, r);
    for (int i = max; i > 0; i--){
        CountSort(a, r, i-1);
    }
}

int main()
{
    string arr[] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    RadixSort(arr, 10);

    cout<<endl<<"Sorted words are:"<<endl;
    for(int i=0; i<10; i++){
      cout << arr[i] << endl;
    }
    cout<<endl;

    return 0;
}
