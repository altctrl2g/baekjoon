
#include <iostream>
using namespace std;

int main() {
    
    int requiredPieces[6] = {1, 1, 2, 2, 2, 8};
    int currentPieces[6];
    int missingPieces[6];
    for (int i = 0; i < 6; i++) {
        cin >> currentPieces[i];
    }

    for (int i = 0; i < 6; i++) {
        missingPieces[i] = requiredPieces[i] - currentPieces[i];
    }

    for (int i = 0; i < 6; i++) {
        cout << missingPieces[i] << ' ';
    }

    return 0;
}
