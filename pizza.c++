#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of locations: ";
    cin >> n;

    int time[10][10]; // assuming max 10 locations
    cout << "Enter time matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> time[i][j];

    bool visited[10] = {false};
    int totalTime = 0;
    int current = 0; // start from location 0
    visited[current] = true;

    cout << "Delivery order: " << current << " ";

    for(int count = 1; count < n; count++) {
        int next = -1;
        int minTime = 1000000; // large number

        for(int i = 0; i < n; i++) {
            if(!visited[i] && time[current][i] < minTime) {
                minTime = time[current][i];
                next = i;
            }
        }

        visited[next] = true;
        totalTime += minTime;
        current = next;
        cout << "-> " << current << " ";
    }

    totalTime += time[current][0]; // return to start
    cout << "-> 0" << endl;

    cout << "Total delivery time: " << totalTime << endl;

    return 0;
}
