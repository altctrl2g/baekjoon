#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int len = (1 << N) + 1;
    cout << len * len;
}