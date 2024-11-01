#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],v[N],a[N],p[N];
int ans;
bool jiasu(int d,int v,int a,int P,int V)
{
    double q=sqrt(double(v*v+2*a*(P-d)));
    if(q>double(V))
        return 0;
    return 1;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++)
        {
            cin>>p[j];
        }
        sort(p+1,p+1+m);
        for(int j=1;j<=n;j++)
        {
            if(d[j]>p[m]) continue;
            if(a[j]==0&&(v[j]>V))
            {
                ans++;
            }
            else
            {
                if(!jiasu(d[j],v[j],a[j],p[m],V))
                {
                    ans++;
                }
            }
        }
        if(!ans)
            cout<<ans<<" "<<m<<endl;
        else
            cout<<ans<<" "<<m-1<<endl;
    }
    return 0;
}
