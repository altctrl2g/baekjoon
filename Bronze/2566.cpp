#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> grid(9, vector<int>(9));

    for (vector<int>& i : grid) {
        for (int& j : i) {
            cin >> j;
        }
    }

    int max = grid[0][0];
    int rowLocation, colLocation;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ( grid[i][j] >= max ) {
                max = grid[i][j];
                rowLocation = i;
                colLocation = j;
            }
        }
    }

    cout << max << '\n';
    cout << rowLocation + 1 << ' ' << colLocation + 1;

    return 0;
}