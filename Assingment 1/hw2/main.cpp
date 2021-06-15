/* CH-231-A
  A1.2(Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
#include "Stack.h"
#include <stdlib.h>
using namespace std;
//main case with instances of different
//data types
int main()
{
    cout<<"int case"<<endl;
    Stack <int> arr1(5);
    int testnum;
    cin>>testnum;
    arr1.push(testnum);
    cout<<"Current size: "<<arr1.getNumEntries()<<endl;
    cout<<"popping it.."<<endl;
    arr1.pop(testnum);
    cout<<"Current size: "<<arr1.getNumEntries()<<endl;
    cout<<endl;

    cout<<"float case"<<endl;
    Stack <float>arr2(3);
    float f1,f2;
    cin>>f1;
    int i;
    for(i=0; i<arr2.gsize(); i++){
        arr2.push(f1);
    }
    cout<<"The last element in the stack is: "<<arr2.back()<<endl;
    cout<<"size is: "<<arr2.getNumEntries()<<endl;
    cout<<"reason: we did it in a for loop of size-times"<<endl;
    cout<<endl;

    cout<<"string case:"<<endl;
    Stack <string>arr3(3);
    string s1,s2,s3;
    int j,k;
    cout<<"enter the two strings: "<<endl;
    cin>>s1>>s2;
    arr3.push(s1);
    arr3.push(s2);
    cout<<"The size is currently: "<<arr3.getNumEntries()<<endl;
    cout<<"Last element is: "<<arr3.back()<<endl;
    cout<<"enter a new string which will be on top: ";
    cin>>s3;
    arr3.push(s3);
    cout<<"the new added element is: "<<arr3.back()<<endl;
    cout<<endl;

    return 0;
}
