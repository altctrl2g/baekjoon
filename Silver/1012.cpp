#include <iostream>
#include <vector>
using namespace std;

int M, N, K;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y, vector<vector<int>> &arr) {
    arr[x][y] = 0;
    for (int i=0; i<4; i++) {
        int p = x + dx[i];
        int q = y + dy[i];

        if (p>=0 && q>=0 && p<=M-1 && q<=N-1) {
            if (arr[p][q] == 1) {
                DFS(p, q, arr);
            }
        }
    }
}

int main() {

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        cin >> M >> N >> K;

        vector<vector<int>> arr(M, vector<int>(N, 0));

        for (int k=0; k<K; k++) {
            int x, y;
            cin >> x >> y;

            arr[x][y] = 1;
        }

        int count = 0;

        for (int m=0; m<M; m++) {
            for (int n=0; n<N; n++) {
                if (arr[m][n] == 1) {
                    count++;
                    DFS(m, n, arr);
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}