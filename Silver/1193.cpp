#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int numerator = 1, denominator = 1;
    int line = 1;

    for (int i = 1; i < X; i++) {
        if (i == line * (line + 1) / 2) {
            if (line % 2 == 0) { numerator++; }
            else { denominator++; }
            line++;
        }

        else {
            if (line % 2 == 0) { numerator++; denominator--;}
            else {numerator--; denominator++;}
        }
    }

    cout << numerator << '/' << denominator;
}