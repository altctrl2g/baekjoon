#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> number;
    unordered_map<string, int> name;

    for (int i=1; i<=N; i++) {
        string p;
        cin >> p;
        
        number.push_back(p);
        name[p] = i;
    }

    for (int m=0; m<M; m++) {
        string s;
        cin >> s;

        if (isdigit(s[0])) {
            cout << number[stoi(s)-1] << '\n';
        }
        else {
            cout << name[s] << '\n';
        }
    }

    return 0;
}
