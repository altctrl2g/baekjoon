#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> num(5);

    for (int i=0; i<5; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    int sum = 0;

    for (int i=0; i<5; i++) {
        sum += num[i];
    }

    int mean = sum/5;
    int median = num[2];

    cout << mean << '\n';
    cout << median << '\n';

    return 0;
}