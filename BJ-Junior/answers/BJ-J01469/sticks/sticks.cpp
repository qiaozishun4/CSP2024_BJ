#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int ans = 1 << 30;

void dfs(int now,int cnt)
{
    if(cnt >= n)
    {
        if(cnt == n)
        {
            ans = min(ans,now);
        }
        return ;
    }
    for(int i = 0;i < 9;i++)
    {
        dfs(now * 10 + i,cnt + num[i]);
    }
    return ;
}

signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    for(int times = 1;times <= t;times++)
    {
        ans = 1 << 30;
        cin >> n;
        for(int i = 1;i <= 9;i++)
        {
            dfs(i,num[i]);
        }
        if(ans == 1 << 30)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
