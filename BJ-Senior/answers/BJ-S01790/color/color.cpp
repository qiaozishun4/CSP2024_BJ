#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],tag[N],ans=0,mark[N];
void dfs(int x,int sum)
{
    if(x>n)
    {
        ans=max(ans,sum);
        return;
    }
    bool flag=false;
    mark[x]=1;
    for(int i=x-1;i>=1;i--)
        if(mark[i]==mark[x]&&a[i]==a[x])
        {
           sum+=a[i];
           flag=true;
           break;
        }
    dfs(x+1,sum);
    if(flag)sum-=a[x];
    mark[x]=2;
    for(int i=x-1;i>=1;i--)
        if(mark[i]==mark[x]&&a[i]==a[x])
        {
           sum+=a[i];
           flag=true;
           break;
        }
    dfs(x+1,sum);
    if(flag)sum-=a[x];
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ans=0;
        memset(tag,-1,sizeof(tag));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1,0);
        cout<<ans<<endl;
    }

    return 0;
}
