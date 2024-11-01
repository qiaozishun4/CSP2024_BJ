#include<bits/stdc++.h>
using namespace std;
int n=[1000005],m=[1000005];
int t;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,m,l,v;
        int t[m],cnt[m]={0},d[n],v[n],a[n];
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i]
        }
        int mx=-1;
        for(int i=1;i<=n;i++)
        {
        `   int o;
            cin>>o;
            mx=max(mx,o),t[o]++;
        }
        for(int i=1;i<=n;i++)
        {
            cnt[i]=cnt[i-1]+t[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if((d[i]>0)&&(v[i]>v&&cnt[l]-cnt[d[i]-1]!=0)) ans++;
            else if(v[i]>v&&cnt[l]-cnt[i]!=0) ans++;
            if(ans) cout<<ans<<m-1;
            else cout<<m;
        }
    }
    return 0;
}