#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,a[N],c[N],n;long long maxx;
inline void dfs(int cur)
{
    if(cur>n)
    {
        int p0=0,p1=0;long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=(c[i]==0?(a[i]==a[p0])*a[i]:(a[i]==a[p1])*a[i]);
            if(c[i]) p1=i;
            else p0=i;
        }
        maxx=max(maxx,ans);
        return;
    }
    c[cur]=0;dfs(cur+1);c[cur]=1;dfs(cur+1);
}
int main()
{
    freopen("color.in","r",stdin);freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;maxx=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(1);
        cout<<maxx<<endl;
    }
    return 0;
}