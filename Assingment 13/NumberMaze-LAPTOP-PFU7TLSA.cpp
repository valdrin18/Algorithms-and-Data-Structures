#include <bits/stdc++.h>
using namespace std;

// same function as in the previous exercise
int min_time(int time[], bool tf[], int n)
{
    int min = INT_MAX, min_index;

    for (int i = 0; i<n; i++)
        if (tf[i] == false && time[i] <= min)
            min = time[i], min_index = i;

    return min_index;
}

struct position{
    int x;
    int y;
};

class PuzzleBoard {
private:
    int **graph;
    int **puzzle;
    int n;
    int ng;
    position current;

public:
    // Subpoint (b)
    PuzzleBoard(int boardSize, int** fields = NULL) {
        n = boardSize;
        puzzle = new int*[n];
        for(int p=0; p<n; p++)
            puzzle[p] = new int[n];
        // Create the puzzle board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                puzzle[i][j] = fields[i][j];
        }
        
        ng = n*n;
        graph = new int*[ng];
        for(int g=0; g<ng; g++)
            graph[g] = new int[ng];
        // initialize graph as zero
        for(int i=0; i<ng; i++){
            for(int j=0; j<ng; j++)
                graph[i][j] = 0;
        }
        // if there is a path from a cell in the puzzle
        // to another, turn graph 1 at that point
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i-puzzle[i][j] >= 0)
                    graph[n*i+j][n*(i-puzzle[i][j])+j] = 1;
                if(j+puzzle[i][j] < n)
                    graph[n*i+j][n*i+(j+puzzle[i][j])] = 1;
                if(i+puzzle[i][j] < n)
                    graph[n*i+j][n*(i+puzzle[i][j])+j] = 1;
                if(j-puzzle[i][j] >= 0)
                    graph[n*i+j][n*i+(j-puzzle[i][j])] = 1;
            }
        }
        // initialize current position at point (0,0)
        current.x = 0;
        current.y = 0;
    }
    /* constructor should create the
    graph (as you defined it in subpoint (a) with the values from fields.
    If fields is null, then initialize the fields of the board with
    random values between 1 and boardSize-1. */

    bool makeMove(int direction){
        int i=current.x;
        int j=current.y;
        if(direction==0){
            if(i-puzzle[i][j] >= 0){
                current.x -=puzzle[i][j];
                return true;
            }
        }
        if(direction==1){
            if(j+puzzle[i][j] < n){
                current.y += puzzle[i][j];
                return true;
            }
        }
        if(direction==2){
            if(i+puzzle[i][j] < n){
                current.x += puzzle[i][j];
                return true;
            }
        }
        if(direction==3){
            if(j-puzzle[i][j] >= 0){
                current.y -= puzzle[i][j];
                return true;
            }
        }
        return false;
    }
    /* makes the move (if valid), direction is 0 for up, 1
    for right, 2 for down, 3 for left. Returns true if the move was
    valid, false otherwise. */

    bool getResult(){
        if(current.x==n-1 && current.y==n-1)
            return true;
        return false;
    }
    /* Returns false if game is not over yet, true if puzzle was solved */

    friend ostream &operator<<(ostream &os, PuzzleBoard const &m){
        // print the puzzle and the graph
        for(int i=0; i<m.n; i++) {
            for(int j=0; j<m.n; j++){
                os << m.puzzle[i][j] << " ";
            }
            os << endl;
        }
        os << endl;
        for(int i=0; i<m.ng; i++) {
            for(int j=0; j<m.ng; j++){
                os << m.graph[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Subpoint (c)

    // Same idea as in the previous exercise to find the shortest path
    // from the beginning of the number maze to the last cell, considering
    // the time difference between each point either as 1 or 0
    int solve(){
        int time[ng];
        bool tf[ng];
        for(int i = 0; i < ng; i++)
            time[i] = INT_MAX, tf[i] = false;

        time[0] = 0;

        for(int count=0; count<ng; count++) {
            int m = min_time(time, tf, ng);
            tf[m] = true;
            for (int j=0; j<ng; j++)
            {
                if(!tf[j] && graph[m][j] && time[m] != INT_MAX
                        && time[m]+graph[m][j] < time[j])
                {
                    time[j] = time[m] + graph[m][j];
                }
            }
        }
        if(time[ng-1]==INT_MAX)
            return -1;
        return time[ng-1];
    }
    /* returns the minimum number of moves needed to solve the puzzle,
    and -1 if it is not solvable. */
};

int main()
{
    int **adj_matrix;
    int n;
    cin >> n;
    adj_matrix = new int *[n];
    for(int i=0;i<n;i++)
        adj_matrix[i] = new int[n];
    cout << "Enter puzzle matrix:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> adj_matrix[i][j];
        }
    }
    cout << endl;
    PuzzleBoard p(n, adj_matrix);
    cout << p;
    if(p.solve() == -1)
        cout << endl << "No solution!" << endl;
    else
        cout << endl << "Minimum number of moves needed to solve the puzzle: " << p.solve() << endl;
    return 0;
}