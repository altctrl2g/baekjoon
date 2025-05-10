#include <iostream>
using namespace std;

int findDifferent(int a, int b, int c) {
    if (a == b) { return c; }
    else if (a == c) { return b; }
    else { return a; }
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x4 = findDifferent(x1, x2, x3);
    y4 = findDifferent(y1, y2, y3);

    cout << x4 << ' ' << y4;

}