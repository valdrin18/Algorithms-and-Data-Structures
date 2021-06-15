#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

//Naive form
int NaiveForm(int n){
    if(n<2){
        return n;
    }
    return NaiveForm(n-1) + NaiveForm(n-2);
}

//Bottom up form
int BottomUp(int n){
    int A[n+1];
    A[0]=0;
    A[1]=1;
    for(int i=2; i<=n; i++){
        A[i]=A[i-1]+A[i-2];
    }
    return A[n];
}

/*
Function to find power recursively
I tried to call ClosedForm by this func
but it returs 0, got no clue why
So I did it in other way

double Power(int x,int n){
    if(n==0){
        return 1; 
    }
    else if(n==1){
        return x;
    }
    else{
        return x*(Power(x,n-1));
    }
}
*/

//Closed form
unsigned long long  ClosedForm(int n){
    unsigned long long result = (1 / sqrt(5)) * ceil(pow(((1 + sqrt(5)) / 2), n));
    return result;
}

//matrix method
int Matrix(int n){
    int A[2][2]={{1,1},{1,0}};
    if(n==0){
        return 0;
    }
    else{
        int I[2][2] = {{1,1},{1,0}};
        for(int i=2; i<=n-1; i++){

            int a =  A[0][0]*I[0][0] + A[0][1]*I[1][0]; 
            int b =  A[0][0]*I[0][1] + A[0][1]*I[1][1]; 
            int c =  A[1][0]*I[0][0] + A[1][1]*I[1][0]; 
            int d =  A[1][0]*I[0][1] + A[1][1]*I[1][1]; 
        
            A[0][0] = a; 
            A[0][1] = b; 
            A[1][0] = c; 
            A[1][1] = d; 
        }
        return A[0][0];
    }         
}

int main()
{   
    //The implement part considering cases
    int i,n;
    ofstream f;
    
    cout<<"Enter 1 for Naive Case"<<endl;
    cout<<"Enter 2 for Bottom up Case"<<endl;
    cout<<"Enter 3 for Closed form Case"<<endl;
    cout<<"Enter 4 for Matrix Case"<<endl;
    cin >> i;
    
    n=0;
    switch(i){
        //in each case left a lvl cap since after it
        //it takes ages to perfom the calculation

        case 1:
            //measure naive case
            f.open("A.txt");
            for(n=0; n<45; n++){
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                NaiveForm(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                double duration1 = duration_cast<nanoseconds>(t2 - t1).count();
                f<< n << " " << setprecision(15) << duration1 << endl;
            }
            f.close();
            break;

        case 2:
            //measure Bottom up case
            f.open("B.txt");
            for(n=0; n<100; n++){
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                BottomUp(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                double duration2 = duration_cast<nanoseconds>(t2 - t1).count();
                f<< n << " " <<duration2 << endl;
            }
            f.close();
            break;

        case 3:
            //measure Closed form case
            f.open("C.txt");
            for(n=0; n<100; n++){
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                ClosedForm(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                double duration3 = duration_cast<nanoseconds>(t2 - t1).count();
                f<< n << " " << duration3 << endl;
            }
            f.close();
            break;

        case 4:
            //measure naive case
            f.open("D.txt");
            for(n=0; n<100; n++){
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                Matrix(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                double duration4 = duration_cast<nanoseconds>(t2 - t1).count();
                f<< n << " " <<  duration4 << endl;
            }
            f.close();
            break;
    }
    return 0;
}
