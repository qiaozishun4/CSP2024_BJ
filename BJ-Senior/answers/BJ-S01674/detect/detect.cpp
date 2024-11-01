#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int d[100005],v[100005],a[100005],p[100005];
struct node
{
    int l,r;
};
bool cmp(node x,node y)
{
    return x.r<y.r;
}
vector<node> q;
int s[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        q.clear();
        for(int i=1;i<=m;i++)s[i]=1e9;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    node ps;
                    ps.l=d[i],ps.r=L;
                    q.pb(ps);
                    // cout<<ps.l<<' '<<ps.r<<endl;
                }
            }
            else if(a[i]<0)
            {
                if(v[i]>V)
                {
                    node ps;
                    ps.l=d[i];
                    ps.r=d[i]+ceil(1.0*(V*V-v[i]*v[i])/2.0/a[i])-1;
                    if(ps.r>L)ps.r=L;
                    q.pb(ps);
                    // cout<<ps.l<<' '<<ps.r<<endl;
                }
            }
            else
            {
                if(v[i]>V)
                {
                    node ps;
                    ps.l=d[i],ps.r=L;
                    q.pb(ps);
                    // cout<<ps.l<<' '<<ps.r<<endl;
                }
                else
                {
                    node ps;
                    ps.l=d[i]+floor(1.0*(V*V-v[i]*v[i])/2.0/a[i])+1;
                    ps.r=L;
                    if(ps.l<=ps.r)q.pb(ps);
                    // cout<<ps.l<<' '<<ps.r<<endl;
                }
            }
        }
        for(int i=0;i<(int)q.size();i++)
        {
            int best1=m+1,best2=0;
            int l=1,r=m;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(p[mid]>=q[i].l)
                {
                    best1=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            l=1,r=m;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(p[mid]<=q[i].r)
                {
                    best2=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            if(best1<=best2)
            {
                ans1++;
                s[best1]=min(s[best1],best2);
            }
        }
        q.clear();
        int mi=1e9;
        for(int i=m;i>=1;i--)if(s[i]<mi){
            mi=s[i];
            node ps;
            ps.l=i,ps.r=s[i];
            q.pb(ps);
        }
        sort(q.begin(),q.end(),cmp);
        // cout<<ans1<<endl;
        int last=0;
        for(int i=0;i<(int)q.size();i++)
        {
            if(q[i].l<=last)continue;
            last=q[i].r;
            ans2++;
        }
        ans2=m-ans2;
        cout<<ans1<<' '<<ans2<<'\n';
    }

    return 0;
}