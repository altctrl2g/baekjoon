#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) v.begin(), v.end()

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> x(N), y(N);
    int a, b;

    for (int i = 0; i < N; i++) { cin >> x[i] >> y[i]; }

    int minx = *min_element(all(x));
    int maxx = *max_element(all(x));
    int miny = *min_element(all(y));
    int maxy = *max_element(all(y));

    cout << (maxx-minx) * (maxy-miny);
    
    return 0;
}