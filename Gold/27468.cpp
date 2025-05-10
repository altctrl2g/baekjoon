#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int num = 0;
    int a[4] = {1, 2, -1, 2};
    int b[4] = {2, -1, 2, 1};

    cout << "YES" << '\n';

    if (n % 4 != 2) {
        for (int i=0; i<n; i++) {
            num += a[i%4];
            cout << num << '\n';
        }
    }

    if (n % 4 == 2) {
        for (int i=0; i<n; i++) {
            num += b[i%4];
            cout << num << '\n';
        }
    }

    return 0;
}