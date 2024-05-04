#include <iostream>
using namespace std;

int main() {
    int input, num = 0;
    cin >> input;
    num = input % 10;
    num = (num * 10) + (input / 10);
    cout << num;
    return 0;
}
