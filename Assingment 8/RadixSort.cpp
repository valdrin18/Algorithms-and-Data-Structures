/* CH08-320211
 (lanuage-Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void BucketSort(vector<int>& arr, int exp) {

    if (exp == 0) {
        return;
    }
    vector<int> b[10];

    for(int i = 0; i < arr.size(); i++){
        int bi = (arr[i] / exp) % 10;
        b[bi].push_back(arr[i]);
    }

    // sort each non-empty bucket
    for(int i = 0; i < 10; i++){
        if(b[i].size() > 1){
            BucketSort(b[i], exp / 10);
        }
    }
    arr.clear();
    // gather all buckets
    int idx = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr.push_back(b[i][j]);
}

void RadixSort(vector<int>& arr) {
    int maxEl = 0;
    // find the largest number (number with most digits)
    for(int i = 0; i < arr.size(); i++){
        maxEl = max(maxEl, arr[i]);
    }

    // find exponent
    int exp = 1;
    while(maxEl /exp > 0) 
        exp *= 10;

    exp /= 10;
    BucketSort(arr, exp);
}

int main() {
    
    vector<int> arr = {579, 73, 2, 34, 5, 909, 163, 40};
    RadixSort(arr);
        for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}