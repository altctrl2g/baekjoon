#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<vector<char>> table(5, vector<char>(15));
    char ch;

    for (int i = 0; i < 5; i++) {
        cin.get(ch);
        if (ch != '\n') { table[i].push_back(ch); }
        else { continue; }
    }

    for (int col = 0; col < 15; col++) {
        for (int row = 0; row < 5; row++) {
            cout << table[row][col];
        }
    }

    return 0;
}