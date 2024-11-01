#include <bits/stdc++.h>
using namespace std;

int n;
int r[100010];
bool vis1[100010];
bool vis2[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
        vis1[i] = 1;
    }
    sort(r + 1, r + n + 1);
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        if(r[i] > 2)flag = true;
    }
    if(flag == false)
    {
        int mid = 0;
        for(int i = 1; i < n; i++)
        {
            if(r[i] < r[i + 1])mid = i;
        }
        cout << max(mid, n - mid) << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            if(r[j] > r[i] && vis1[i] && !vis2[j] && i != j)
            {
                vis1[i] = 0;
                vis2[j] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis1[i])cnt++;
    }
    cout << cnt << endl;
    return 0;
}
