#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M)), B(N, vector<int>(M)), sum(N, vector<int>(M));

    for (vector<int>& i : A) {
        for (int& j : i) {
            cin >> j;
        }
    }

    for (vector<int>& i : B) {
        for (int& j : i) {
            cin >> j;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A.at(i).at(j) + B.at(i).at(j) << ' ';
        }
        cout << '\n';
    }

    return 0;
}