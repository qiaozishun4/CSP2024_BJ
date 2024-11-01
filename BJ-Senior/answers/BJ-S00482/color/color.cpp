#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=2e5+10;
int n,a[N],c[N],ans;

void dfs(int x)
{
    if(x>n)
    {
        int cnt=0;
        for(int i=2;i<=n;i++)
            for(int j=i-1;j>=1;j--)
                if(a[j]==a[i]&&c[j]==c[i])
                {
                    cnt+=a[j];break;
                }
        ans=max(ans,cnt);
        return;
    }
    dfs(x+1);
    c[x]=1;dfs(x+1);c[x]=0;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
