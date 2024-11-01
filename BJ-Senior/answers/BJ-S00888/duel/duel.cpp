#include <bits/stdc++.h>
using namespace std;

int n, maxn;
int a[100005];
int s[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != a[i - 1])
        {
            maxn = max(maxn, cnt);
            cnt = 0;
        }
        cnt++;
    }
    maxn = max(maxn, cnt);
    cout << maxn;
    return 0;
}
