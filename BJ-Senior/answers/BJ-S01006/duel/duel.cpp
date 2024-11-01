#include <bits/stdc++.h>
using namespace std;
int n, a[100010], num[100010];
int main ()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        Max = max(Max, num[a[i]]);
    }
    cout << Max << endl;
    return 0;
}
