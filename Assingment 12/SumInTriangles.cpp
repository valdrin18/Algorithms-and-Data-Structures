#include <iostream>
#include <vector>
using namespace std;

//function to find the sum in triangles and its path
void SIT(int **arr, int n){
    
    //create second array for the path
    int **arr2 = new int*[n];
    for(int i=0; i<n; i++){
        arr2[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            arr2[i][j] = arr[i][j];
        }
    }

    //calculating the sum of highest
    for(int i=n-2; i >= 0; i--){
        for(int j = 0; j <= i+1; j++){
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }
    cout<<endl<<"Sum is: "<<arr[0][0]<<endl;

    //finding that longest path
    int max = 0;
    for(int i = 0; i < n; i++){
        if(arr[i][max] > arr[i][max+1]){
            max++;
        }
        cout<<arr2[i][max]<<" ";
    }
    
    //memory deallocation
    for(int i = 0; i<n; i++){
        delete[] arr2[i];
    }
    delete[] arr2;
}

//main function
int main(){

    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    while((n <= 1) || (n > 100)){
        cout<<"Error, enter a valid number between 1 and 100!"<<endl;
        cout<<"Your input: ";
        cin>>n;
    }

    //create a 2D array
    int **arr = new int*[n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[n];
    }

    //fill it with values
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            check:
            cin>>arr[i][j];
            if(arr[i][j] < 0 || arr[i][j] > 10000){
                cout<<"Error, enter a valid number between 1 and 10000!"<<endl;
                cout<<"Your input: ";
                goto check;
            }
        }
    }

    //memory deallocation
    SIT(arr,n);
    for(int i =0; i<n; i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Answer to question 12.2 b)

    Since the total number of elements is n(n+1)/2, the time complexity is O(n^2)
    different from brute force with running time 2^k with k= n(n-1)/2. This comes
    from the fact that every element has two possible paths apart from last row

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Answer to question 12.2 c)

    Greedy algorithms picks smaller sub-problems and solves them hoping it will work
    for the general problem, where as dynamic programming solves all small sub-problems
    and picks the most efficent one. This means, greedy would not work since it would go 
    with another pick which would not relate to the solution of the whole problem
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/