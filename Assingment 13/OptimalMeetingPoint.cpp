#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int find_meetup_city(int** cities, int number_of_cities, int your_city, int friend_city){
    //algorithm for computing 
    for (int k = 0; k < number_of_cities; k++){
        for (int i = 0; i < number_of_cities; i++){
            for (int j = 0; j < number_of_cities; j++){
                if (cities[i][k] + cities[k][j] < cities[i][j]){
                    cities[i][j] = cities[i][k] + cities[k][j]; 
                }
            }
        }
    }
    //get city with minimum
    int res = INT_MAX;
    int city;
    for(int i = 0; i < number_of_cities; i++) {
        if (res > max(cities[your_city][i], cities[friend_city][i])){
            res = max(cities[your_city][i], cities[friend_city][i]);
            city = i;
        }
    }
    return city;    
}

int main() {
    
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // dynamically allocate 2d array nxn
    int** cities = new int*[n];
    for (int i = 0; i < n; i++) {
        cities[i] = new int[n]; 
    }

    cout << "Fill out the adjacency matrix " << n << "x" << n << " representing time between cities:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cities[i][j];
            if (cities[i][j] == -1)
                cities[i][j] = INT_MAX;
            if (i == j)
                // distance to itself is obviously zero
                cities[i][j] = 0;
        }
    }

    int p, q;
    cout << "Enter your city: ";
    cin >> p;
    cout << "Enter your friend's city: ";
    cin >> q;
    // call the function to find the optimal meetup point
    cout << "The optimal meetup point: " << find_meetup_city(cities, n, p, q) << endl;

    // deallocate memory
    for (int i = 0; i < n; i++) {
        delete cities[i]; 
    }
    delete[] cities;

    return 0;
}