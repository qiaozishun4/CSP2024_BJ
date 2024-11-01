#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long a[200005];
struct Node {long long ans = 0; int lb = 0,lr = 0;};
Node vis[200005][2];
Node dfs(int pos,int num)
{
    if(pos == 1)
    {
        if(num == 0)
        {
            return {0,1,0};
        }
        else
        {
            return {0,0,1};
        }
    }
    if(vis[pos][num].ans != 0 && vis[pos][num].lb != 0 && vis[pos][num].lr != 0)
    {
        return vis[pos][num];
    }
    long long ret = -1;
    int b,r;
    Node ta = dfs(pos - 1,0);
    Node tb = dfs(pos - 1,1);
    if(num == 0)
    {
        long long tmp = ta.ans;
        if(a[ta.lb] == a[pos])
        {
            tmp += a[pos];
        }
        if(tmp > ret)
        {
            ret = tmp;
            b = pos;
            r = ta.lr;
        }
        tmp = tb.ans;
        if(a[tb.lb] == a[pos])
        {
            tmp += a[pos];
        }
        if(tmp > ret)
        {
            ret = tmp;
            b = pos;
            r = tb.lr;
        }
    }
    else
    {
        long long tmp = ta.ans;
        if(a[ta.lr] == a[pos])
        {
            tmp += a[pos];
        }
        if(tmp > ret)
        {
            ret = tmp;
            r = pos;
            b = ta.lb;
        }
        tmp = tb.ans;
        if(a[tb.lr] == a[pos])
        {
            tmp += a[pos];
        }
        if(tmp > ret)
        {
            ret = tmp;
            r = pos;
            b = tb.lb;
        }
    }
    return vis[pos][num] = {ret,b,r};
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i],vis[i][0] = vis[i][1] = {0,0,0};
    cout << max(dfs(n,0).ans,dfs(n,1).ans) << '\n';
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}
