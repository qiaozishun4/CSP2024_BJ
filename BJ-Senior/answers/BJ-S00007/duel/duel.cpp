#include<bits/stdc++.h>
using namespace std;

int n, r[100010], sum[100010], num[100010], cnt;
map<int, int>mp;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i], mp[r[i]]++;
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; i++)
        if(num[cnt] != r[i])
        {
            num[++cnt] = r[i];
        }
    for(int i = 1; i <= cnt; i++)
    {
        int x = sum[i - 1], y = mp[num[i]];
        if(x == y) sum[i] = y;
        else if(x > y) sum[i] = x;
        else if(x < y) sum[i] = y;
    }
    cout << sum[cnt] << endl;
    return 0;
}