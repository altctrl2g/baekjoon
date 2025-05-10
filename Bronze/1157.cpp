#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    string word;
    cin >> word;

    vector<string> croatian = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (string& letter : croatian) {
        while (word.find(letter) != string::npos) {
            word.replace(word.find(letter), letter.length(), "*");
        }
    }

    cout << word.length();

    return 0;
}
