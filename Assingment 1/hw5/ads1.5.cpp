/* CH-231-A
  A1.5(Cpp)
 Valdrin Smakaj
Vsmakaj@jacobs-university.de
*/

#include <iostream>
#include <vector>
using namespace std;
//main function
int main()
{
    //created string-type vector
    vector <string> vec1;
    string s1,s2;
    //code to get string input until "END"
    while(1){
        getline(cin,s1);
        if(s1=="END"){
            break;
        }
        //insert at vector
        vec1.push_back(s1);
    }
    //if size is bigger than 5, then swap the ele
    vector<string>::size_type si = vec1.size();
    if(vec1.size()>=5){
        s2=vec1[1];
        vec1[1]=vec1[4];
        vec1[4]=s2;
       // swap(vec1[1], vec1[4]);
    }
    else{
        cout<<"String does not contain at least 5 elements"<<endl;
    }

    //code for comma print
    vector<string>::iterator i;
    vec1.at(si-1) = "???";
    for(i=vec1.begin(); i!=vec1.end(); i++){
        if(i==(vec1.end()-1)){
            cout<<*i;
        }
        else{
        cout<<*i<<", ";
        }
    }
    cout<<endl;

    //code for semicolon print
    vector<string>::iterator i2;
    for(i2=vec1.begin(); i2!=vec1.end(); i2++){
        if(i2==(vec1.end()-1)){
            cout<<*i2;
        }
        else{
        cout<<*i2<<"; ";
        }
    }
    cout<<endl;

    //code for reverse print
    vector<string>::iterator i3;
    for(i3 = vec1.end()-1; i3 != (vec1.begin()-1); i3--){
        cout<< *i3<<" ";
    }
    cout<<endl;
    return 0;
}
