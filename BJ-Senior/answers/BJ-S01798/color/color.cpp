#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
int T;
int col[N],a[N],sum;//col 0:r  col 1:b
int n;
void init()
{
    memset(a,0,sizeof a);
    memset(col,-1,sizeof col);
    sum=0;
    n=0;
}
int lf(int k)
{
    for(int i=k; i>=1; i--)
    {
        if(col[i]==col[k]&&i!=k)
        {
            return i;
        }
    }
    return -1;
}
int chck()
{
    int res=0;
    for(int i=1; i<=n; i++)
    {
        int k=lf(i);
        if(k!=-1&&a[k]==a[i])
        {
            res+=a[i];
        }
    }
    return res;
}
void dfs(int dep)
{
    if(dep>n)
    {
        sum=max(sum,chck());
        return;
    }
    col[dep]=1;
    dfs(dep+1);
    col[dep]=0;
    dfs(dep+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        init();
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }

        dfs(1);
        cout<<sum<<'\n';

    }
    return 0;
}
