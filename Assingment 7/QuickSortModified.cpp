/* CH08-320211
 (lanuage-Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;


void Partition(int A[], int begin, int end, int &q, int &u){


    int p1 = A[begin];// pivot
    int p2 = A[end];// pivot
    int q1 = begin + 1;
    int q2 = end - 1;

    for (int i = begin + 1; i <= q2; i++){

        if (A[i] < p1){ 
            swap(A[i], A[q1]);
            q1++;
        }
        else if(A[i] >= p2){
            while(A[q2] > p2 && i < q2){
                q2--;
            }
            swap(A[i],A[q2]);
            q2--;
            if(A[i]<p1){
                swap(A[i],A[q1]);
                q1++;
            }
        }
    }
    q1--;
    q2++;

    swap(A[begin], A[q1]);
    swap(A[end], A[q2]);
    q = q1;
    u = q2;
}

void ModQuickSort(int A[], int begin, int end)
{
    if (begin < end)
    {
        int q,u;
        Partition(A, begin, end,q,u);
        ModQuickSort(A, begin, q-1);
        ModQuickSort(A, q+1, u-1);
        ModQuickSort(A, u+1, end);
    }
}

//for the randomized part
void RandPartition(int A[], int begin, int end, int &q, int &u){

    int p1 = rand() % (end - begin + 1) + begin;
    int p2 = rand() % (end - begin + 1) + begin;
    while(p1 == p2){
        p1 = rand() % (end - begin + 1) + begin;
        p2 = rand() % (end - begin +1 ) + begin;
    }
    swap(A[p1], A[begin]);
    swap(A[p2], A[begin+1]);
    Partition(A, begin, end,q,u);
}

void RandModQuickSort(int A[], int begin, int end)
{
    if (begin < end)
    {
        int q,u;
        RandPartition(A, begin, end,q,u);
        RandModQuickSort(A, begin, q-1);
        RandModQuickSort(A, q+1, u-1);
        RandModQuickSort(A, u+1, end);
    }
}


//Main function
int main(){

    srand(time(NULL));

    //Modfied QuickSort implementation
    int arr1[] = {5, 1, 7, 2, 3, 4};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    ModQuickSort(arr1, 0, n-1);

    cout<<"Sorted array 1: ";
    for (int i=0; i < n; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl;

    //Modfied Randomized QuickSort implementation
    int arr2[] = {5, 1, 7, 2, 3, 4};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    RandModQuickSort(arr1, 0, n-1);

    cout<<"Sorted array 2: ";
    for (int i=0; i < n; i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}