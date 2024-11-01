#include<bits/stdc++.h>
#define int long long
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
using namespace std;
template<typename A,typename...B>inline void rd(A&x,B&...y){
    cin>>x;
    if constexpr(sizeof...(y))rd(y...);
}
const int N=1e6+33,L=30;
#define li (i<<1)
#define ri (i<<1|1)
int n,m,a[N],b[N],c[N],l,ans[N],f[N],yi[N];
char s[L][N];set<int>st[N];
void so(){
    fr(u,1,1<<l+1){
        f[u]=yi[u]=ans[u]=0;
    }
    fr(i,1,1<<l){
        int u=i+(1<<l)-1;
        while(u){f[u]+=i;u=(u>>1);}
    }
    fr(i,1,n){
        int u=i+(1<<l)-1,r=1,tt=i;
        f[u]=yi[u]=i;
        u=(u>>1);
        while(u){
            tt=(tt-1)/2+1;
            int x=u<<1,y=u<<1|1;
            if(s[r][tt]=='1')swap(x,y);
            if(yi[x]){
                if(a[yi[x]]>=r){
                    f[u]=f[x];
                    yi[u]=yi[x];
                }else{
                    //ans = ans[y]
                    f[u]=f[y];
                    yi[u]=yi[y];
                }
            }else{
                //ans=ans[x]+ans[y]
                yi[u]=0;
                f[u]=f[x]+f[y];
            }
            u=u>>1;
            r++;
        }
        int e;
        for(e=0;(1<<e)<i;e++);
        ans[i]=f[(i+(1<<l)-1)>>e];
    }
}
signed main(){
    file("arena.in","arena.out");
    rd(n,m);
    fr(i,1,n)rd(b[i]);
    fr(i,1,m)rd(c[i]);
    for(l=0;(1<<l)<n;l++);
    fr(i,1,l){
        scanf("%s",s[i]+1);
    }
    int Q;
    rd(Q);
    while(Q--){
        int xr[4]={};
        fr(i,0,3)rd(xr[i]);
        fr(i,1,n)a[i]=b[i]^xr[i%4];
        so();
        int an=0;
        fr(i,1,m){
            an^=(ans[c[i]]*i);
        }
        pt("%lld\n",an);
    }
    return 0;
}
