#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string word;
    cin >> word;
    int wordLength = word.length();

    bool isSame = true;
    for (int i = 0; i < wordLength; i++) {
        if (word[i] != word[wordLength - i - 1]) {
            isSame = false;
        }
    }

    cout << (isSame ? '1' : '0');

    return 0;
}
