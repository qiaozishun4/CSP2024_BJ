#include<bits/stdc++.h>
#define int long long
using namespace std;

int r[100005];
int dif = 1;
int num[100005];
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    int cnt = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        if (r[i] != r[i - 1])
        {
            num[dif] = cnt;
            //cout << num[dif] << endl;
            dif++;
            cnt = 1;
        }
        else
        {
            cnt++;
            //cout << cnt << endl;
        }

    }
    for (int i = 2; i <= dif; i++)
    {
        num[i] = max(num[i], num[i - 1]);
    }
    cout << num[dif];
}
