#include <bits/stdc++.h>
using namespace std;
int n,ans,c[16];
bool f[16];
int p()
{
    int sum=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
            if(f[j]==f[i])
                if(c[i]==c[j]){sum+=c[i];break;}
    }
    return sum;
}
void dfs(int step)
{
    if(step>n)
    {
        ans=max(ans,p());
        return;
    }
    f[step]=1;
    dfs(step+1);
    f[step]=0;
    dfs(step+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>c[i];
        dfs(1);
        cout<<ans<<endl;
    }
}