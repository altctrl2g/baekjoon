#include <iostream>

using namespace std;

int main() {

    int n = 0;

    while (true) {
        cin >> n;
        if (n == -1) {break;}
        int a[100000];
        int idx = 0;
        int sum = 0;

        for (int i = 1; i < n; i++) {
            if (n % i == 0) { a[idx] = i; idx++; }
        }

        for (int i = 0; i < idx; i++) {
            sum += a[i];
        }

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < idx-1; i++) {
                cout << a[i] << " + ";
            }
            cout << a[idx-1] << '\n';
        }
        else { cout << n << " is NOT perfect." << '\n';}

    }
    return 0;
}
