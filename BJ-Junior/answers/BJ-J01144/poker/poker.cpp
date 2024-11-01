#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string ss[55];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ss[i];
    }
    sort(ss + 1, ss + n + 1);
    n = unique(ss + 1, ss + n + 1) - ss - 1;
    cout << 52 - n << endl;
    return 0;
}
