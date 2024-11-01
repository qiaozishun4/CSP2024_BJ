#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n,a[N],f[N],ans=0;
void dfs(int d)
{
    if(d>=n)
    {
        int res=0;
        for(int i=1;i<n;i++)
            for(int j=i-1;j>=0;j--)
                if(f[j]==f[i])
                {
                    if(a[j]==a[i]) res+=a[i];
                    break;
                }
        ans=max(ans,res);
        return;
    }
    f[d]=0;
    dfs(d+1);
    f[d]=1;
    dfs(d+1);
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
