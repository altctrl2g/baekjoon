#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    int C;
    int quarter, dime, nickel, penny;

    for (int i = 0; i < T; i++) {
        cin >> C;
        quarter = C / 25;
        C -= quarter * 25;
        dime = C / 10;
        C -= dime * 10;
        nickel = C / 5;
        penny = C - nickel * 5; 

        cout << quarter << " " << dime << " " << nickel << " " << penny << endl;

        return 0;
    }

}