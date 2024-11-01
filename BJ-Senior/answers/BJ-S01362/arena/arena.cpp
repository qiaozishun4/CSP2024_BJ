#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200010
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pa;
int n,m,T,ta[MAXN],c[MAXN],a[MAXN],tx[4],ld,sm[MAXN],lim,ans[20],lg[MAXN];
string d[20];
bool check()
{
    for(int i=1;i<=lim;i++)
        for(int j=1;j<=(1<<(i-1));j++)
            if(d[i][j]=='1') return false;
    return true;
}
pa work(int x,int dep)
{
    if(dep==ld+1) return mp(a[x],x);
    pa tl=work(x*2-1,dep+1),tr=work(x*2,dep+1);
    if(d[ld-dep+1][x]==0)
    {
        if(tl.fi>=ld-dep+1) return tl;
        return tr;
    }
    else
    {
        if(tr.fi>=ld-dep+1) return tr;
        return tl;
    }
}
signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","r",stdin);
    cin>>n>>m;
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int i=1;i<=n;i++) cin>>ta[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    while((1<<lim)<n) lim++;
    for(int i=1;i<=lim;i++) cin>>d[i],d[i]=' '+d[i];
    cin>>T;
    while(T--)
    {
        cin>>tx[0]>>tx[1]>>tx[2]>>tx[3];
        for(int i=1;i<=n;i++) a[i]=ta[i]^tx[i%4];
        for(int i=1;i<=lim;i++)
            ld=i,ans[i]=work(1,1).se;
        int sa=0;
        ans[0]=1;
        for(int i=1;i<=m;i++) sa^=(i*ans[lg[c[i]]]);
        cout<<sa<<'\n';
    }
    return 0;
}
