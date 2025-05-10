#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    int result = INT_MAX;

    for (int i=0; i<n; i++) {
        cin >> board[i];
    }

    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            char leftTop = board[i][j];
            int count1 = 0, count2 = 0;

            if (leftTop == 'W') {
                for (int x=0; x<8; x++) {
                    for (int y=0; y<8; y++) {
                        if ((x+y) % 2 == 0) {
                            if (board[i+x][j+y] != 'W') { count1++; }
                            if (board[i+x][j+y] != 'B') { count2++; }
                        }
                        else {
                            if (board[i+x][j+y] != 'B') { count1++; }
                            if (board[i+x][j+y] != 'W') { count2++; }
                        }
                    }
                }
            }

            else if (leftTop == 'B') {
                for (int x=0; x<8; x++) {
                    for (int y=0; y<8; y++) {
                        if ((x+y) % 2 == 0) {
                            if (board[i+x][j+y] != 'B') { count1++; }
                            if (board[i+x][j+y] != 'W') { count2++; }
                        }
                        else {
                            if (board[i+x][j+y] != 'W') { count1++; }
                            if (board[i+x][j+y] != 'B') { count2++; }
                        }
                    }
                }
            }

            result = min(result, min(count1, count2));

        }
    }
    cout << result;

    return 0;
}
