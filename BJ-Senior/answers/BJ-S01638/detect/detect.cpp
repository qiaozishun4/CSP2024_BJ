#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn =1e5+6;
ll t,cnt;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        int d[maxn],v[maxn],a[maxn];
        int p[maxn];
        ll n,m,l,V;
        cin>>n>>m>>l>>V;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]<=V&&a[i]==0)continue;
            else{
                for(int j=1;j<=m;j++)
                {
                    for(int t=1;t<=l/v[i];t++)
                    {
                        int v2=v[i]+a[i]*t;
                        double s=v[i]*t+0.5*a[i]*t*t;
                        if(abs(p[j]-d[i]+s)<1e-5)
                        {
                            if(V<sqrt(v[i]*v[i]+2*a[i]*s))cnt++;
                            else if((v2*v2-v[i]*v[i])/(2*a[i])==s)
                            {
                                if(v2>V)cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<" "<<cnt;
    }
}
