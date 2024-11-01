#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mp[]={6,2,5,5,4,5,6,3,7,6};
int n,ans,cur;
void dfs(int x)
{
    if(x==0)
    {
        ans=min(ans,cur);
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        if(mp[i]<=x)
        {
            cur=cur*10+i;
            dfs(x-mp[i]);
            cur/=10;
        }
    }
    return ;
}
void sol()
{
    cin>>n;
    ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=9;i++)
    {
        cur=0;
        if(mp[i]<=n)
        {
            cur=cur*10+i;
            dfs(n-mp[i]);
        }
    }
    if(ans==0x3f3f3f3f3f3f3f3f) ans=-1;
    cout<<ans<<endl;
    return ;
}
signed main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--) sol();
    return 0;
}
