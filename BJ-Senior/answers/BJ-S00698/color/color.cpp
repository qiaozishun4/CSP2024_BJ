#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,ans;
int a[200005]={0},mp[2];

void dfs(int pos,int ys,int anss)
{
    if(pos==n+1)
    {
        ans=max(ans,anss);
        return;
    }
    if(mp[ys]==a[pos])
    {
        anss+=a[pos];
    }
    int x=mp[ys];
    mp[ys]=a[pos];
    dfs(pos+1,0,anss);
    dfs(pos+1,1,anss);
    mp[ys]=x;
}

signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        mp[0]=mp[1]=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(0,0,0);
        cout<<ans<<endl;
    }
}
