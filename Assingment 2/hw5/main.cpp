#include <iostream>
#include <ctime>
#include <set>
using namespace std;

int main()
{   //created set
    set <int> s1;
    srand(time(NULL));
    //filled with random values
    for(int i=0; i<6; i++){
        int n=(rand()%49)+1;
        s1.insert(n);
    }//printed them
    for(set<int>::iterator i1=s1.begin(); i1!=s1.end(); i1++){
        cout<<*i1<<" ";
    }
    return 0;
}
