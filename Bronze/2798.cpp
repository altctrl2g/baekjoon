#include <iostream>

using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int max = 0;
    int sum;

    for (int i = 0; i < N-2; i++) {
        for (int j = i+1; j < N-1; j++) {
            for (int k = j+1; k < N; k++) {
                int sum = a[i] + a[j] + a[k];
                if (sum <= M && sum > max) { max = sum; }
            }
        }
    }

    cout << max;

    return 0;
}