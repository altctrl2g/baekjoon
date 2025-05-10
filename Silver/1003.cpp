#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);

    for (int i=0; i<n; i++) {
        cin >> num[i]; 
    }

    int max = *max_element(num.begin(), num.end());

    vector<pair<int, int>> count(2);
    count[0] = {1, 0};
    count[1] = {0, 1};

    for (int i=2; i<=max; i++) {
        int first = count[i-2].first + count[i-1].first;
        int second = count[i-2].second + count[i-1].second;
        count.push_back({first, second});
    }

    for (int i=0; i<n; i++) {
        cout << count[num[i]].first << ' ' << count[num[i]].second << '\n';
    }

    return 0;
}
