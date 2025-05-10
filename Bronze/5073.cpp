#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    while (a!=0 || b!=0 || c!=0) {
        if (a+b<=c || b+c<=a || c+a<=b) { cout << "Invalid" << '\n'; }
        else if (a==b && b==c && c==a) { cout << "Equilateral" << '\n'; }
        else if (a!=b && b!=c && c!=a) { cout << "Scalene" << '\n'; }
        else { cout << "Isosceles" << '\n'; }

        cin >> a >> b >> c;
    }
    return 0;
}