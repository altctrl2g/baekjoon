#include <iostream>

using namespace std;

int main() {
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    x = (c*e - b*f) / (a*e - d*b);
    y = (c*d - f*a) / (b*d - e*a);

    cout << x << ' ' << y;

    return 0;
}
