#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main() {

    int N;
    cin >> N;

    vector<string> arr;
    for (int n=0; n<N; n++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}