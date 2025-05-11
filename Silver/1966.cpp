#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int testCase;
    int n, m;

    cin >> testCase;
    for (int t=0; t<testCase; t++) {
        cin >> n >> m;

        queue<pair<int, int>> priority;

        for (int i=0; i<n; i++) {
            int p;
            cin >> p;

            priority.push({p,i});
        }

        int count = 0;

        for (int i=0; i<n; i++) {
            
            int temp = 

        }

    }


    return 0;
}