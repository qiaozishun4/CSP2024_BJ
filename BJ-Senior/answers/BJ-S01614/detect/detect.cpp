#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
int t,cs,ubs,n,m,l,rv,d[maxn],v[maxn],a[maxn],ms[maxn];
bool ub[maxn];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cs=0;
        ubs=0;
        cin>>n>>m>>l>>rv;
        for(int i=0;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<=m;i++)
        {
            cin>>ms[i];
            ub[i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(ms[j]-d[i]<0) continue;
                if(sqrt(pow(v[i],2)+2*a[i]*(ms[j]-d[i]))<0) break;
                if(sqrt(pow(v[i],2)+2*a[i]*(ms[j]-d[i]))>rv)
                {
                    cs++;
                    ub[j]=1;
                }
            }
        }
        for(int i=0;i<=m;i++) if(ub[i]) ubs++;
        cout<<cs<<" "<<m-ubs<<endl;
    }
    return 0;
}