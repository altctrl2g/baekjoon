#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int count = 0;

    while (n >= 3) {
        if (n % 5 == 0) { 
            count += n/5; 
            n = 0; 
        }
        else { 
            n -= 3; 
            count++; 
        }
    }

    cout << (n == 0 ? count : -1); 

    return 0;
}