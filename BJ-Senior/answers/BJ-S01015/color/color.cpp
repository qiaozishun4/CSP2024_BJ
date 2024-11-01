#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int dp[N],a[N],b[N];
int t,n;
long long ans=0;
void dfs(int x)
{
    if(x>n)
    {
        int x0=0,x1=0;
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==1)
            {
                if(x1) 
                {
                    if(a[x1]==a[i]) sum+=a[x1];
                }
                x1=i;
            } 
            else
            {
                if(x0)
                {
                    if(a[x0]==a[i]) sum+=a[x0];
                }
                x0=i;
            }
        }
        ans=max(ans,sum);
        return ;
    }
    for(int i=0;i<=1;i++)
    {
        b[x]=i;
        dfs(x+1);
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
		memset(dp,0,sizeof(dp));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(0);
        cout<<ans<<"\n";
    }
    return 0;
}
