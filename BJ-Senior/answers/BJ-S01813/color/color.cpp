#include <bits/stdc++.h>
using namespace std;

int n;

int v[20];

int a[200010];

int maxn;

void dfs(int st)
{
    if(st > n)
    {
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i-1; j>0; j--)
            {
                if(v[i] == v[j])
                {
                    if(a[i] == a[j]) cnt += a[j];
                    break;
                }
            }
        }
        maxn = max(maxn, cnt);
        return ;
    }
    v[st] = 0;
    dfs(st + 1);
    v[st] = 1;
    dfs(st + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        maxn = 0;
        dfs(1);
        cout << maxn << endl;
    }
}
