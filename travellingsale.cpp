#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int tspBruteForce(vector<vector<int>>& dist, int n) {
    vector<int> cities;
    for (int i = 1; i < n; i++) {
        cities.push_back(i); // start from city 0, so we exclude it
    }

    int minCost = INT_MAX;

    do {
        int currentCost = 0;
        int k = 0; // start from city 0
        for (int i = 0; i < cities.size(); i++) {
            currentCost += dist[k][cities[i]];
            k = cities[i];
        }
        currentCost += dist[k][0]; // return to starting city

        minCost = min(minCost, currentCost);
    } while (next_permutation(cities.begin(), cities.end()));

    return minCost;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int result = tspBruteForce(dist, n);
    cout << "Minimum cost (Brute Force): " << result << endl;

    return 0;
}
