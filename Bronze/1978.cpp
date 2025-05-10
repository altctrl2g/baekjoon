#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int n;
    bool isPrime;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        cin >> n;

        isPrime = true;

        for (int j = 2; j < n; j++)
            if (n % j == 0) { isPrime = false; }

        if (isPrime && n != 1) { cnt++; }
    }
    
    cout << cnt;

    return 0;
}
