#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LSA(vector <int> v1){

    int size = v1.size();
    vector<vector<int>>v2(size);
    v2[0].push_back(v1[0]);

    for(int i = 1; i<size; i++){
        for(int j = 0; j<i; j++){
            if((v1[i] > v1[j]) && (v2[j].size() > v2[i].size())){
                v2[i] = v2[j];
            }
        }
        v2[i].push_back(v1[i]);
    }

    vector<int> max = v2[0];
    for (vector<int> i: v2) {
        if (i.size() > max.size()) {
            max = i;
        }
    }
    for (int i: max) {
        cout << i << " ";
    }
}

int main(){

    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    LSA(v);
    return 0;
}