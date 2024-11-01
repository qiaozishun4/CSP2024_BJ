#include <bits/stdc++.h>
using namespace std;
int const N=1e5+3;
int cnt,n,m,L,V,p[N],ind[N];
vector < pair<int,int> > c,chao;
vector <int> g[N<<1];
bool vis[N<<1],flag;
inline void cal()
{
    int d,v,a;
    scanf("%d%d%d",&d,&v,&a);
    if(a==0) 
    {
        if(v>V) c.push_back({d,L});
    }
    else if(a>0) 
    {
        if(v>V) c.push_back({d,L});
        else 
        {
            int pos=ceil((1.0*V*V-1.0*v*v)/(2.0*a)+0.0001)+d;
            if(pos<=L) c.push_back({pos,L});
        }
    }
    else 
    {
        if(v>V)
        {
            int pos=(int)((1.0*V*V-1.0*v*v)/(2.0*a)-0.000001)+d;
            c.push_back({d,min(pos,L)});
            flag=1;
        }
    }
}
inline void solve1()
{
    for(auto i:c)
    {
        int l=i.first,r=i.second;
        int pos1=upper_bound(p+1,p+m+1,l-1)-p,pos2=upper_bound(p+1,p+m+1,r)-p-1;
        if(pos1>pos2) continue;
        cnt++;
    }
    printf("%d ",cnt);
}
inline void solve2()
{
    for(auto i:c)
    {
        int l=i.first,r=i.second;
        int pos1=upper_bound(p+1,p+m+1,l-1)-p,pos2=upper_bound(p+1,p+m+1,r)-p-1;
        if(pos1>pos2) continue;
        cnt++,chao.push_back({l,r});
        g[m+cnt].clear(),vis[m+cnt]=0;
        // cout<<"l="<<l<<" r="<<r<<endl;
        // cout<<pos1<<" "<<pos2<<endl;
        for(int j=pos1;j<=pos2;++j) g[m+cnt].push_back(j),g[j].push_back(m+cnt),ind[j]++;
    }
    int num=0,ans=0;
    // for(int i=1;i<=m;++i) cout<<ind[i]<<endl;
    while(num<cnt)
    {
        int pos=0;
        for(int i=1;i<=m;++i) if(!vis[i] && ind[pos]<ind[i]) pos=i;
        vis[pos]=1;
        // cout<<"pos="<<pos<<endl;
        for(int i:g[pos])
        {
            if(vis[i]) continue;
            vis[i]=1;
            // cout<<i-cnt<<" ";
            for(int j:g[i]) if(!vis[j]) ind[j]--;
            num++;
        }
        // cout<<endl;
        ans++;
    }
    printf("%d\n",m-ans);
}
inline void solve()
{
    flag=0;
    scanf("%d%d%d%d",&n,&m,&L,&V);
    c.clear(),chao.clear(),cnt=0;
    for(int i=1;i<=n;++i) g[i].clear(),cal();
    for(int i=1;i<=m;++i) vis[i]=ind[i]=0,scanf("%d",&p[i]);
    sort(p+1,p+m+1);
    solve1();
    // for(auto i:chao) cout<<"l="<<i.first<<" r="<<i.second<<endl;
    if(!flag)
    {
        if(cnt) m--;
        printf("%d\n",m);
        return ;
    }
    cnt=0;
    solve2();
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    // T=10;
    while(T--) solve();
    return 0;
}