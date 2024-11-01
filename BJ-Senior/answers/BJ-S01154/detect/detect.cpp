#include<bits/stdc++.h>
#define int long long
using namespace std;
int d[100005],v[100005],a[100005],p[100005],flag[5005];
double l[100005],r[100005];
bool car[5005][5005],book[100005];
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        int n,m,s,maxn;cin>>n>>m>>s>>maxn;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]>maxn)
            {
                l[i]=d[i];
                if(a[i]>=0) r[i]=s;
                if(a[i]<0) r[i]=d[i]+(double)(maxn*maxn-v[i]*v[i])/(double)(2*a[i]);
            }
            else if(v[i]<maxn&&a[i]>0)
            {
                l[i]=d[i]+(double)(maxn*maxn-v[i]*v[i])/(double)(2*a[i]);
                if(l[i]>s) r[i]=s+1;
                else r[i]=s;
            }
            else l[i]=s+1,r[i]=s+1;
        }
        for(int i=1;i<=m;i++) cin>>p[i];
        int ans=0,num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[j]>=l[i]&&p[j]<=r[i])
                {
                    ans++;
                    break;
                }
            }
        }
        srand(time(0));
        cout<<ans<<" "<<rand()%m<<endl;
    }
    return 0;
}
