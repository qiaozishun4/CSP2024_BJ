#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int ans = n;
    for(int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        if(a[x] == 0) ans--;
        a[x]++;
    }
    int maxn = 0;
    for(int i = 1; i <= 100000;i++)
    {
        maxn = max(maxn, a[i]);
    }
    cout << maxn << endl;
    return 0;
}
