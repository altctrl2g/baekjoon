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

        while (!priority.empty()) {

            int cur = priority.front().first;
            
            queue<pair<int, int>> temp = priority;

            bool isFirst = true;
            while (!temp.empty()) {
                if (temp.front().first > cur) {
                    isFirst = false;
                }
                temp.pop();
            }

            if (isFirst) { 
                count++;
                if (priority.front().second == m) {
                    break;
                }
                priority.pop();
            }
            else {
                    priority.push(priority.front());
                    priority.pop();
                }


        }

        cout << count << '\n';

    }


    return 0;
}