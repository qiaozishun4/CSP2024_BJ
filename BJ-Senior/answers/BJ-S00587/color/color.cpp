#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        cout << max(abs(t%(t-5)*3), 1) << endl;
    return 0;
}
