#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    vector<int> v1;

    for(i=1; i<31; i++){
        v1.push_back(i);
    }
    v1.push_back(5);
    reverse(v1.begin(),v1.end());

    vector<int>::iterator i1=v1.begin();
    while(i1!=v1.end()){
        cout<<*i1<<" ";
        i1++;
    }
    cout<<endl;
    replace(v1.begin(), v1.end(),5,129);
    i1=v1.begin();
    while(i1!=v1.end()){
        cout<<*i1<<" ";
        i1++;
    }
    cout<<endl;
    return 0;
}
