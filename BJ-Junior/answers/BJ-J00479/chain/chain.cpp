#include<bits/stdc++.h>
#define rep(i,S,T) for(int i=S;i<=T;++i)
#define per(i,T,S) for(int i=T;i>=S;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=2e5+10,R=105;
int T,n,K,q,siz[N],vis[N];
vector<int> a[N];
int now[N][R];
struct node{
    int r,c;
}ask[N];
void solve(){
    read(n);read(K);read(q);K--;
    int lim=0;
    rep(i,1,n){
        read(siz[i]);
        a[i].clear();
        rep(j,1,siz[i]){
            int x;read(x);
            a[i].push_back(x);lim=max(lim,x);
        }
    }
    int rlim=0;
    rep(i,1,q){
        read(ask[i].r);read(ask[i].c);
        rlim=max(rlim,ask[i].r);
    }
    memset(now,0,sizeof(now));
    now[1][0]=-1;
    rep(r,1,rlim){
        rep(i,1,n){
            int R=0;
            rep(j,1,siz[i]){
                if(now[a[i][j-1]][r-1]==i) continue;
                if(now[a[i][j-1]][r-1]!=0){
                    for(int l=max(R,j+1);l<=min(siz[i],j+K);++l){
                        int &g=now[a[i][l-1]][r];
                        if(!g) g=i;
                        else if(g!=i) g=-1;R=max(R,l);
                    }
                }
            }
        }
    }
    rep(i,1,q){
        if(now[ask[i].c][ask[i].r]!=0) printf("1\n");
        else printf("0\n");
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    read(T);while(T--) solve();
    return 0;
}
/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
1 2
1 4
2 4
3 4
6 6
1 1
7 7
*/
