#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
string f[N+10] = {"0", "-1", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88"};
int T, n;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    for (int i = 15; i <= N; i++) f[i] = f[i-7] + "8";
    while (T--)
    {
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}