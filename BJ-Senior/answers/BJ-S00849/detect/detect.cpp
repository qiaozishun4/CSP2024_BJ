#include<bits/stdc++.h>
using namespace std;
int n,m,l,z,a[100005],d[100005],v[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>z;
        int fl=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]>0)
            {
                fl=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        if(fl==0)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=m;j>=1;j--)
                {
                    if(p[j]<d[i])
                    {
                        j=0;
                    }
                    else
                    {
                        if(v[i]>z)
                        {
                            ans++;
                        }
                        j=0;
                    }
                }
            }
            if(ans==0)
            {
                cout<<ans<<" "<<m<<'\n';
            }
            else
            {
                cout<<ans<<" "<<m-1<<'\n';
            }
        }
    }
    return 0;
}
//lz
