#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d[100010],v[100010],a[100010];
int p[100010];
int tot; pair<int,int> range[100010];
int dp[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int t; cin>>t; while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1; i<=n; ++i) cin>>d[i]>>v[i]>>a[i];
        for(int i=1; i<=m; ++i) cin>>p[i];
        tot=0;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]>=0)
            {
                int el=1,er=m,wz=-1;
                while(el<=er)
                {
                    int mid=el+er>>1;
                    if(p[mid]>=d[i] && 1ll*v[i]*v[i]+2ll*a[i]*(p[mid]-d[i])>1ll*V*V) wz=mid,er=mid-1;
                    else el=mid+1;
                }
                if(wz!=-1) range[++tot]={wz,m};
            }
            else
            {
                int wzl=lower_bound(p+1,p+m+1,d[i])-p;
                int el=wzl,er=m,wz=-1;
                //double len=(V*V-v[i]*v[i])/2.0/a[i];
                while(el<=er)
                {
                    int mid=el+er>>1;
                    //if(p[mid]-d[i]<len) wz=mid,el=mid+1;
                    if(1ll*v[i]*v[i]+2ll*a[i]*(p[mid]-d[i])>1ll*V*V) wz=mid,el=mid+1;
                    else er=mid-1;
                }
                if(wz!=-1) range[++tot]={wzl,wz};
            }
        }
        sort(range+1,range+tot+1);
        multiset<int> stl,str;
        int wz=1;
        for(int i=1; i<=tot; ++i)
        {
            stl.insert(range[i].first);
            str.insert(range[i].second);
            while((*--stl.end())>*str.begin())
            {
                stl.erase(stl.find(range[wz].first));
                str.erase(str.find(range[wz].second));
                ++wz;
            }
            dp[i]=dp[wz-1]+1;
        }
        cout<<tot<<' '<<m-dp[tot]<<'\n';
    }
    return 0;
}
