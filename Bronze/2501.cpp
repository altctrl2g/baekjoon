#include <iostream>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;
    int i = 0, count = 0;

    while (count < K && i <= N) {
        i++;
        if (N % i == 0) {count++;}
    }
    cout << (i > N ? 0 : i);

    return 0;
}
