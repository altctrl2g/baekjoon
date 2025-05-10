#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int M, N;
    cin >> M >> N;

    int min;
    int sum = 0;

    for (int i = N; i >= M; i--) {
        if (isPrime(i)) { sum += i; min = i; }
    }

    if (sum == 0) { cout << -1; }
    else { cout << sum << '\n' << min; }
    return 0;
}
