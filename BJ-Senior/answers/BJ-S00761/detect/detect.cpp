#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,m,L,V,d[N],v[N],a[N],p[N],sa[N];
int erfen(int l,int r,double x)
{
    while(l<r)
    {
        int mid=(l+r)/2+1;
        if(1.0*p[mid]>=x)r=mid-1;
        else l=mid+1;
    }
    if(1.0*p[l]>=x)return l-1;
    else return l;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int ans=0,cnt=0;
        scanf("%d %d %d %d",&n,&m,&L,&V);
        memset(sa,0,sizeof(sa));
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    int x=lower_bound(p+1,p+m+1,d[i])-p;
                    if(x!=m+1)
                    {
                        ans++,sa[x]++,sa[m+1]--;
                    }
                }
            }
            if(a[i]<0)
            {
                if(v[i]>V)
                {
                    double t=1.0*(V+v[i])*(V-v[i])/(2*a[i])+d[i];
                    int x=erfen(1,m,t);
                    if(x!=-1)
                    {
                        int x_1=lower_bound(p+1,p+m+1,d[i])-p;
                        if(x>=x_1&&x_1!=m+1)
                        {
                            ans++,sa[x_1]++,sa[x+1]--;
                        }
                    }
                }
            }
            if(a[i]>0)
            {
                double t=1.0*(V+v[i])*(V-v[i])/(2*a[i])+d[i];
                if(t<=p[m])
                {
                    int x=lower_bound(p+1,p+m+1,ceil(t))-p;
                    if(1.0*p[x]==t)x++;
                    if(x!=m+1)
                    {
                        ans++,sa[x]++,sa[m+1]--;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            sa[i]+=sa[i-1];
            if(sa[i]==ans||sa[i]==0)cnt++;
        }
        cout<<ans<<" "<<cnt<<endl;
    }
    return 0;
}
