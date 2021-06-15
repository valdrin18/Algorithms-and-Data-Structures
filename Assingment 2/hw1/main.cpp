#include <iostream>
#include <list>
#include <fstream>
#include <stdio.h>

using namespace std;
int main()
{

    ofstream f;
    list <int> A;
    list <int> B;
    int n,i,k;
    while(true){
        cin>>n;
        if(n<=0){
            break;
        }
        B.push_front(n);
        A.push_back(n);

    }

    list <int>::iterator i1=A.begin();
    list <int>::iterator i2=B.begin();

    while(i1!=A.end()){
        cout<<*i1<<" ";
        i1++;
    }

    //code to print elements of list B in file
    f.open("listB.txt");
    if(!f.is_open()){
        cout<<"ERROR 404"<<endl;
        exit(1);
    }
    while(i2!=B.end()){
        f<<*i2<<" ";
        i2++;
    }
    f.close();
    cout<<endl<<endl;
    //moved first to last element
    A.splice(A.end(),A,A.begin());
    B.splice(B.end(),B,B.begin());

    //printed with komma
    i1=A.begin();
    while(i1!=A.end()){
        if(i1!=A.begin()){
            cout<<", ";
        }
        cout<<*i1;
        i1++;
    }
    cout << endl;

    i2=B.begin();
    while(i2!=B.end()){
        if(i2!=B.begin()){
            cout<<", ";
        }
        cout<<*i2;
        i2++;
    }

    cout<<endl<<endl;
    //merged and printed with spaces
    A.sort();
    B.sort();
    A.merge(B);

    i1=A.begin();
    while(i1!=A.end()){
        cout<<*i1<<" ";
        i1++;
    }
    return 0;
}
