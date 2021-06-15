/* CH08-320211
 (lanuage-Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//Implementation of QuickSort Lomoto partition as on the lecture slides
//Source: Slides
int Lomoto(int arr[], int p, int q){

    int x = arr[p];// pivot
    int i = p; 
 
    for (int j = p+1; j <= q; j++){

        if (arr[j] <= x){
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[p], arr[q]);
    return (i);
}

void QuickSortLomoto(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Lomoto(A, p, r);
        QuickSortLomoto(A, p, q-1);
        QuickSortLomoto(A, q+1, r);
    }
}


//Implementation of QuickSort Hoare partition (using Wikipedia or other sources)
//Source: GeekForGeeks
int Hoare(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}

void QuickSortHoare(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Hoare(A, p, r);
        QuickSortHoare(A, p, q);
        QuickSortHoare(A, q+1, r);
    }
}



//Implementation of QuickSort ”Median-of-three” partition
//Source: GeekForGeeks
int Median(int A[], int p, int q)
{
  int left, right, pivot;

  left = p;
  right = q;
  pivot = A[p];

  while ( left < right )
  {
    while ( A[right] > pivot )
      right--;

    while ( (left < right) && (A[left] <= pivot) )
      left++;

    if ( left < right )
     swap(A[left], A[right] );
  }

  A[p] = A[right];
  A[right] = pivot;

  return right;
}

int M( int A[], int p, int q )
{
	int middle = (p+q)/2;

	if ( A[p] > A[middle] )
		swap( A[middle], A[p] );
	if ( A[p] > A[q] )
		swap( A[p], A[q] );
	if ( A[middle] > A[q] )
		swap( A[q], A[middle] );

	swap(A[middle], A[p]);

	return Median(A, p, q);
}

void QuickSortMedian(int A[], int p, int r)
{  
    if (p < r)
    {
        int q = M(A, p, r);
        QuickSortMedian(A, p, q-1);
        QuickSortMedian(A, q+1, r);
    }
}



//Main function
int main(){

    int arr1[] = {5, 1, 7, 2, 3, 4};
    int arr2[] = {5, 1, 7, 2, 3, 4};
    int arr3[] = {5, 1, 7, 2, 3, 4};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int o = sizeof(arr3)/sizeof(arr3[0]);

    QuickSortLomoto(arr1, 0, n-1);
    QuickSortHoare(arr2, 0, m-1);
    QuickSortMedian(arr3, 0, o-1);

    printf("Sorted array by Lomoto Partition: \n");
    for (int i=0; i < n; i++){
        cout<<arr1[i]<<" ";
    }
    printf("\n");

    printf("Sorted array by Hoare Partition: \n");
    for (int i=0; i < m; i++){
        cout<<arr2[i]<<" ";
    }
    printf("\n");

    printf("Sorted array by Median-of-three partition: \n");
    for (int i=0; i < o; i++){
        cout<<arr3[i]<<" ";
    }
    printf("\n");

    //Now testing with larger sizes input
    ofstream f;
    f.open("QS.txt");
    srand(time(NULL));
    clock_t start,stop;
    int i,limit=100000;

    for(i=0; i<limit; i++){

      int a1[1000],a2[1000],a3[1000];
      for(int l=0; l<=1000; l++){
         a1[l] = (rand() % 1000) + 1;
      }

      for(int l=0; l<1000; l++){
         a2[l] = a1[l];
         a3[l] = a1[l];
      }
      
      start=clock();
      QuickSortLomoto(a1,0,1000);
      stop=clock();
      double t1 =(double) (stop-start)/CLOCKS_PER_SEC;

      start=clock();
      QuickSortHoare(a2,0,1000);
      stop=clock();
      double t2 =(double) (stop-start)/CLOCKS_PER_SEC;

      start=clock();
      QuickSortMedian(a3,0,1000);
      stop=clock();
      double t3 =(double) (stop-start)/CLOCKS_PER_SEC;

      f<<i<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
    }
    f.close();
    return 0;
}