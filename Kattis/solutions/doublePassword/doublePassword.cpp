#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    string password1, password2;
    int power = 0;
    cin >> password1 >> password2;

    for (int i = 0; i < 4; i++) {
        if (password1[i] != password2[i]) {
            power++;
        }
    }
    cout << pow(2, power);
    return 0;
}
