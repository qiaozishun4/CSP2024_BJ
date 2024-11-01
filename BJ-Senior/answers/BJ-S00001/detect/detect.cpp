#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int _;
int n,m;
long long L,V;
long long d[N],a[N],v[N];
long long p[N];
long long calc(int i,int j)
{
    return 2ll*(p[j]-d[i])*a[i]+v[i]*v[i];
}
vector<int>tp[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>_;
    while(_--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=m;i++)
        {
            tp[i].clear();
        }
        sort(p+1,p+1+m);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
			
            if(d[i]>p[m])continue;
            if(a[i]>=0)
            {
               // cerr<<i<<"??\n";
                int l=(lower_bound(p+1,p+1+m,d[i])-p),r=m;
                long long df=calc(i,m);
                if(df<=V*V)continue;
                ans++;
                int ll=m,rr=m;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(calc(i,mid)>V*V)
                    {
                        ll=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                tp[ll].push_back(rr);
            }
            else
            {
                int l=(lower_bound(p+1,p+1+m,d[i])-p),r=m;
               
                long long df=calc(i,l);
                //cerr<<df<<' '<<V*V<<"??\n";
                if(df<=V*V)continue;
                ans++;
                int ll=l,rr=l;
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(calc(i,mid)>V*V)
                    {
                        rr=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                tp[ll].push_back(rr);
            }
        }
        set<int>s;
        int num=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<tp[i].size();j++)s.insert(tp[i][j]);
            if(!s.empty()&&(*s.begin())<=i)
            {
                num++;
                s.clear();
            }
        }
        cout<<ans<<' '<<m-num<<'\n';
    }
}
