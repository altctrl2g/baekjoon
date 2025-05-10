#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int A, B, V;
    cin >> A >> B >> V;
    int days;
    if ((V-A) % (A-B) == 0) { days = (V-A) / (A-B) + 1;}
    else { days = (V-A) / (A-B) + 2;}
    cout << days;

    return 0;
}