#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,H=19,inf=2147483647;
int x[4],A[N],a[N],c[N];
int n,q,k,lg;
string d[H];
bool ispow2[N];
namespace Part1{
    bool flg[N];
    int doit(int km,int lgm){
        vector<int> v;
        for(int i=1;i<=km;++i)v.push_back(i);
        for(int p=1;p<=lgm;++p){
            vector<int> v1;
            for(int i=0;i<(int)v.size();i+=2){
                int x=i+d[p][i/2]-'0';
                if(a[v[x]]>=p)v1.push_back(v[x]);
                else v1.push_back(v[x^1]);
            }
            v=v1;
        }
        return v[0];
    }
    ll solve1(int m){
        for(int i=1;i<=m;++i)a[i]=A[i]^x[i%4];
        int km=1,lgm=0;
        while(1){
            if(km>=m)break;
            km*=2,++lgm;
        }
        for(int i=1;i<=km;++i)flg[i]=0;
        int p=km-m;
        for(int s=0;s<(1<<p);++s){
            for(int i=0;i<p;++i)a[m+1+i]=((s>>i)&1)?0:inf;
            flg[doit(km,lgm)]=1;
        }
        ll res=0;
        for(int i=1;i<=km;++i)res+=flg[i]*i;
        return res;
    }
    void solve(){
        ll res=0;
        for(int i=1;i<=q;++i)res^=(i*solve1(c[i]));
        cout<<res<<'\n';
    }
    int resQ[N];
    void solveT(){
        for(int i=1;i<=n;i*=2)resQ[i]=solve1(i);
        ll res=0;
        for(int i=1;i<=q;++i)res^=(i*resQ[c[i]]);
        cout<<res<<'\n';
    }
};
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    for(int i=1;i<N;i*=2)ispow2[i]=1;
    cin>>n>>q;
    bool isA=1,isB=1;
    for(int i=1;i<=n;++i)cin>>A[i];
    for(int i=1;i<=q;++i)cin>>c[i],isA&=ispow2[c[i]];
    k=1,lg=0;
    while(1){
        if(k>=n)break;
        k*=2,++lg;
    }
    for(int i=1;i<=lg;++i){
        cin>>d[i];
        for(int j=0;j<d[i].size();++j)isB&=(d[i][j]=='0');
    }
    int T;cin>>T;
    while(T--){
        for(int i=0;i<4;++i)cin>>x[i];
        if(n<=8&&q<=8)Part1::solve();
        else if(isA)Part1::solveT();
        // if(n<=8&&q<=8)Part1::solve();
        // else if(isA)PartA::solve();
    }
    return 0;
}