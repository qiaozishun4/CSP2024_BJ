#include<bits/stdc++.h>

using namespace std;

int t,n;
int num[] = {6,2,5,5,4,5,6,3,7,6};
int ans[] = {-1,1,7,4,2,6,8,10,18,22,20,60,80,88,108,188,206,208,288,600};
/*
void dfs(int d,int cnt)
{
    if (d >= n)
    {
        if (d == n)
        {
            ans = min(ans,cnt);
            f = true;
            //exit(0);
        }
        return;
    }
    for (int i = 9;i >= 0;i--)
    {
        if (d == 0 && i == 0)
            continue;
        //cout << str+to_string(i) << "\n";
        dfs(d+num[i],cnt*10+i);
    }
    return;
}
*/
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for (int i = 1;i <= t;i++)
    {
        cin >> n;
        cout << ans[n-1] << "\n";
    }
    return 0;
}
