#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[1000005],v[1000005],a[1000005],ch[10000005],b[1000005],ans=0,cnt=1;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++)
        {
            cin>>ch[j];
        }
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0)
            {
                if(d[j]<=ch[m]&&v[j]>V)
                {
                    ans++;
                }
            }
            if(a[j]>0)
            {
                int x=(V*V-v[j]*v[j]);
                int y=(2*a[j]);
                if(x/y+d[j]<=ch[m])
                {
                    ans++;
                }
            }
        }
        cout<<ans<<" "<<n-1<<'\n';
    }
    return 0;
}
