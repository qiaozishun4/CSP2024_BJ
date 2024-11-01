#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+10,maxv=1e6+10;
int n;
int a[maxn];
int lst[maxv],val[maxn],pre[maxn],sum[maxn];
int f[maxn][2];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&a[i]==a[i-1]) val[i]=a[i];
        else val[i]=0;
        pre[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+val[i];
    for(int i=1;i<=n;i++)
    {
        f[i][0]=f[i][1]=0;
        if(pre[i])
        {
            f[i][1]=f[pre[i]][1]+a[i]+sum[i-1]-sum[pre[i]];
            f[i][0]=f[pre[i]][0]+a[i]+sum[i-1]-sum[pre[i]];
            if(pre[i]!=i)
            {
                f[i][1]=max(f[i][1],f[pre[i]+1][0]+sum[i-1]-sum[pre[i]+1]+a[i]);
                f[i][0]=max(f[i][0],f[pre[i]+1][1]+sum[i-1]-sum[pre[i]+1]+a[i]);
            }
        }
        f[i][1]=max(f[i][1],max(f[i-1][0],f[i-1][1]));
        f[i][0]=max(f[i][0],max(f[i-1][0],f[i-1][1]));
        //cout<<f[i][0]<<" "<<f[i][1]<<endl;
    }
    cout<<max(f[n][0],f[n][1])<<endl;
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        sol();
    }
	return 0;
}
