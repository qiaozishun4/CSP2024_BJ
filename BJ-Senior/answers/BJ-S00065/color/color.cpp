#include<bits/stdc++.h>
using namespace std;

int n;
int t;
int a[100000];
int color[100000];
int ans;

void dfs(int cnt,int maxn)
{
    if(cnt==n)
    {
        if(color[n-1]==color[n])
            maxn+=a[n-2];
        ans=max(ans,maxn);
        return;
    }
    if(cnt>2)
    {
        if(color[n-1]==color[n])
            maxn+=color[n-2];
    }
    color[n+1]=1;
    dfs(cnt+1,maxn);
    color[n+1]=0;
    dfs(cnt+1,maxn);
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>n;
        ans=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        if(n<3)cout<<0<<endl;
        else if(n==3)cout<<a[1]<<endl;
        else
        {
            dfs(1,0);
            cout<<ans<<endl;
        }

    }
    return 0;
}
