#include <iostream>
#include <deque>
using namespace std;
//main function
int main()
{
    //created and put elements
    deque <float> A;
    float n;
    while(true){
        cin>>n;
        if(n==0){
            break;
        }
        else if(n>0){
            A.push_back(n);
        }
        else{
            A.push_front(n);
        }
    }

    //print by space
    deque <float>::iterator di=A.begin();
    while(di!=A.end()){
        cout<<*di<<" ";
        di++;
    }
    cout<<endl<<endl;

    //insert 0 between elements
    for(int j=0; j<A.size(); j++){
        if(A[j]>0){
            di=A.insert(A.begin()+j,0);
            break;
        }
    }

    //print by semicolon
    di=A.begin();
    while(di!=A.end()){
        if(di!=A.begin()){
            cout<<"; ";
        }
        cout<<*di;
        di++;
    }
    return 0;
}
