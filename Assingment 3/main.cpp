//Course: CH-231-A
//Valdrin Smakaj
//V.smakaj@jacobs-university.de

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//the selection sort algorithm
void selecSort(int A[],int n){
	int min, x;
	for(int i=0; i<=n-2; i++){
		min = i;
		for (int j=i+1; j<n; j++){
			if(A[j] < A[min]){
				min = j;
			}
		}
		x = A[i];
		A[i] = A[min];
		A[min] = x;
	}
}
//function to print the elements of the array
void print(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}
//main function
int main()
{
    cout << "First we show with a simple array that is works"<<endl;
    int A1[5] = {4,2,3,6,1};
    selecSort(A1,5);
    print(A1,5);
    ofstream f;
    f.open("A.txt");
    //other examples now follow
    //here we have to measure by time in order to check
    //how long it takes for the sort to happen also depending
    //on different, best, average and worst cases

    clock_t start,stop;
    //take a couple of array instances

    //random array instance
    for(int l=0; l<100000; l=l+10){

        int i,arr[l];
        srand(time(NULL));
        for(i=0; i<l; i++){
            arr[i]=(rand()%100)+1;
        }
        start=clock();
        selecSort(arr,l);
        stop=clock();

        double randtime =(double) (stop-start)/CLOCKS_PER_SEC;


        //best array instance
        int bestarr[l];
        for(i=0; i<l; i++){
            bestarr[i]=i+1;
        }
        start=clock();
        selecSort(bestarr,l);
        stop=clock();
        double bestime=(double)(stop-start)/CLOCKS_PER_SEC;


        //worst array instance
        int worstarr[l];
        for(i=l; i>=0; i--){
            worstarr[l-i]=i+1;
        }
        start=clock();
        selecSort(worstarr,l);
        stop=clock();
        double worstime=(double)(stop-start)/CLOCKS_PER_SEC;


        f<<l<<" "<<randtime<<" "<<bestime<<" "<<worstime<<endl;
    }

    return 0;
}
