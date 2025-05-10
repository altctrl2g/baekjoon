#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int sum = 0, temp;

    for (int i=0; i<n; i++) {
        sum = i;
        temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if ( sum == n) { cout << i; return 0; }
    }

    cout << 0;
    return 0;
}
