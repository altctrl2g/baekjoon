#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int count = 0;
    int num = 0;
    

    while (count != n) {

        num++;
        string strNum = to_string(num);
        bool isNum = false;

        for (int i=0; i<strNum.length(); i++) {
            if (strNum[i] == '6' && strNum[i+1] == '6' && strNum[i+2] == '6') { isNum = true; }
        }

        if (isNum) { count++; }
    }

    cout << num;

    return 0;
}