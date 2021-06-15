#include <iostream>
#include <vector>
using namespace std;

struct A{
    int startTime;
    int finishTime;
};

vector <A> ActivitySelection(vector <A> S){

    vector<A> ActivitySolution; 
    int LST;
    int index;

    while (!S.empty()) {
        LST = 0;
        //find activity with the latest start time
        for (int i = 0; i < S.size(); i++){
            if (S[i].startTime > LST){
                LST = S[i].startTime;
                index = i;
            }
        }
        
        //overlap checks
        int x = 0;
        for (int i = 0; i < ActivitySolution.size(); i++){
            if (S[index].finishTime > ActivitySolution[i].startTime){
                x++;
            }
        }
        if (x == 0){
            ActivitySolution.push_back(S[index]);
        }
        S.erase(S.begin() + index);
    }
    return ActivitySolution;
}

int main() {
    
    vector <A> S;
    S = {{6, 7}, {6, 13},{1, 12}, {4, 5},{7, 9}, {1, 3}};
    S = ActivitySelection(S);
    int n = S.size();

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1<< ":" << endl;
        cout << S[i].startTime << " " << S[i].finishTime << endl << endl;
    }
    return 0;
}