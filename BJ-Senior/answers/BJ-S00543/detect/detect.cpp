#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,d[100005],v1[100005],a[100005],p[100005],ans=0,an,m1[100005];
int main()
{

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t>>n>>m>>l>>v;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i]>>v1[i]>>a[i];
    }
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        an=0;
        for(int j=1;j<=m;j++)
        {
            if(d[i]>p[j]) continue;
            if((p[j]-d[i])*a1[i]+v[i]<=0) continue;
            if((p[j]-d[i])*a1[i]+v[i]>v) 
            {
                an=1;
                m1[j]=1;
            }
        }
        if(an=1) ans++;
    }
    cout<<ans;
    ans=0;
    for(int i=1;i<=m;i++)
    {
        if(m1[i]==1) ans++;
    }
    cout<<" "<<ans;
    return 0;
}