#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514],c[114514],cnt[114514],ans;
int check()
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            if(c[j]==c[i])
            {
                if(a[j]==a[i])
                    cnt[i]=a[i];
                else
                    cnt[i]=0;
                break;
            }
        }
        num+=cnt[i];
    }
    ans=max(ans,num);
}
void dfs(int x)
{
    if(x==n+1)
    {
        check();
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(c,0,sizeof(c));
        memset(cnt,0,sizeof(cnt));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<"\n";
    }

    return 0;
}
