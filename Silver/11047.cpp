#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i=0; i<n; i++) {
        cin >> coin[i];
    }

    int count = 0;

    for (int i=n-1; i>=0; i--) {
        if (k >= coin[i]) {
            count += k/coin[i];
            k %= coin[i];
        }
    }

    cout << count;

    return 0;
}
