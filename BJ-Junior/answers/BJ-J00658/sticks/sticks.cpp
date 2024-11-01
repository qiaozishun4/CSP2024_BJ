#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e18 + 10;
int t, n, len;
int st[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, sum[50020];
int f[100020] = {-1, -1, 1, 7, 4, 2, 0, 8}, l[100020];
int ans = MAX;

void fun(int n, int sum)
{
    if(n <= 0)
    {
        if(n == 0) ans = min(ans, sum);
        return ;
    }
    if(sum >= ans || n == 1) return ;
    if(f[n] == -1)
    {
        return;
    }
    if(f[n] != 0)
    {
        sum = sum * pow(10, l[n] +1) + f[n];
        ans = min(ans, sum);
        return ;
    }
    for(int i = 0; i <= 9; i++)
    {
        if(i == 0 && sum == 0) continue;
        fun(n - st[i], sum * 10 + i);
    }
    return ;
}

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = MAX;
        fun(n, 0);
        if(ans == MAX) ans = -1;
        cout << ans << endl;
        len = 0;
        while(ans > 0) len++, ans /= 10;
        f[n] = ans, l[n] = len;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
