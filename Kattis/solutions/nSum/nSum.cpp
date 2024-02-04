#include <iostream>
using namespace std;

int main(void)
{
    int n, sum = 0, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }

    cout << sum;
    return 0;
}