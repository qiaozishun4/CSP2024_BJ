#include <bits/stdc++.h>
using namespace std;
int n, k[100005], cnt;
bool cmp(int x, int y)
{
    return x < y;
}
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> k[i];
    }
    sort(k+1, k+n+1, cmp);
    for(int i=1; i<=n; ++i)
    {
        bool flag=true;
        for(int j=1; j<=n; ++j)
        {
            if(k[i]>k[j])
            {
                flag=false;
            }
        }
        if(flag)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}