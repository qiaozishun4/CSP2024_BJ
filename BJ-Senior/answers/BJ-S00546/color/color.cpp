#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[200005],ans;
bool t[200005];
void dfs(ll d)
{
    if(d>n)
    {
        ll l[2]={0,0},ret=0;
        for(ll i=1;i<=n;i++)
        {
            if(a[l[t[i]]]==a[i]) ret+=a[i];
            l[t[i]]=i;
        }
        ans=max(ans,ret);
        return;
    }
    t[d]=0;
    dfs(d+1);
    t[d]=1;
    dfs(d+1);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
    {
        ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
	return 0;
}
