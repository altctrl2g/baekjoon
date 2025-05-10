#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> cost(n);
    vector<int> time(n);

    for (int i=0; i<n; i++) {
        cin >> cost[i];
    }

    sort(cost.begin(), cost.end());

    time[0] = cost[0];
    for (int i=1; i<n; i++) {
        time[i] = time[i-1] + cost[i];
    }
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += time[i];
    }

    cout << sum;


    return 0;
}