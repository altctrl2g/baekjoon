#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int start = 1;
    int layer = 1;

    while (start < N) {
        start += 6 * layer;
        layer++;
    }
    
    cout << layer;
}