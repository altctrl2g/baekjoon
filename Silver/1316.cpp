#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int N;
    string word;
    int count = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        int length = word.length();
        
        for (int i = 0; i < length - 1; i++) {
            if (word[i] == word[i+1] or i == length - 2) { continue; }
            else {
                if (word.find(word[i], i + 2) != string::npos) { count++; break; }
            }
        }
    }
   
   cout << N - count;

    return 0;
}
