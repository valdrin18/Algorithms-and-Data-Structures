/* CH-231-A
  A1.4(Cpp)
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
    string s1;
    //enter strings continuously until "END"
    while(1){
        cin>>s1;
        if(s1=="END"){
            break;
        }
        //put them into the vector
        vec1.push_back(s1);
    }
    //print them separated with spaces
    for(unsigned int i=0; i<vec1.size(); ++i){
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    //print by iterator separated with commas
    vector<string>::iterator i;
    for(i=vec1.begin(); i!=vec1.end(); i++){
        if(i==(vec1.end()-1)){
            cout<<*i;
        }
        else{
        cout<<*i<<", ";
        }
    }
    cout<<endl;
    return 0;
}
