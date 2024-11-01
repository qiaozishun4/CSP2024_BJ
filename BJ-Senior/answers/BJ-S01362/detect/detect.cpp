#include <bits/stdc++.h>
#define MAXN 100010
#define int long long
#define pb push_back
using namespace std;
int T,n,m,L,V,d[MAXN],v[MAXN],a[MAXN],p[MAXN],vis[MAXN],buk[MAXN];
vector <int> qj[MAXN];
stack <int> st;
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i],qj[i].clear();
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=0)
            {
                if(p[m]<d[i]) continue;
                int vt=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
                if(vt>V*V)
                {
                    vis[i]=1,ans++;
                    int l=lower_bound(p+1,p+1+m,d[i])-p,r=m,mid;
                    while(l<=r)
                    {
                        if(l==r)
                        {
                            qj[l].pb(m);
                            break;
                        }
                        mid=(l+r)>>1;
                        if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V) r=mid;
                        else l=mid+1;
                    }
                }
            }
            else
            {
                if(p[m]<d[i]) continue;
                int pos=lower_bound(p+1,p+1+m,d[i])-p;
                int vt=v[i]*v[i]+2*a[i]*(p[pos]-d[i]);
                if(vt>V*V)
                {
                    vis[i]=1,ans++;
                    int l=pos,r=m,mid;
                    while(l<=r)
                    {
                        if(l==r)
                        {
                            qj[pos].pb(l);
                            break;
                        }
                        mid=(l+r+1)>>1;
                        if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V) l=mid;
                        else r=mid-1;
                    }
                }
            }
        }
        cout<<ans<<' ';
        memset(buk,0,sizeof(buk));
        int sa=0;
        for(int i=1;i<=m;i++)
        {
            for(int x:qj[i])
            {
                st.push(x),buk[x]++;
            }
            if(buk[i])
            {
                sa++;
                while(st.size())
                {
                    int tt=st.top();
                    buk[tt]--;
                    st.pop();
                }
            }
        }
        cout<<m-sa<<'\n';
    }
    return 0;
}
