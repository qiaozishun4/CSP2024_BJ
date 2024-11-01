#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e5+10;
int n,tot;
int a[maxn];
struct node{
    int x,cnt;
}f[maxn];
inline void ipt(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
inline void init(){
    sort(a+1,a+n+1);
    int p=a[1];
    f[++tot].x=a[1];
    f[tot].cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]==p)f[tot].cnt++;
        else {
            f[++tot].x=a[i];
            p=a[i];
            f[tot].cnt=1;
        }
    }
}
inline void solve(){
    int g=0,ans=0;
    for(int i=1;i<=tot;i++){
        if(g>=f[i].cnt)
            ans+=f[i].cnt;
        else {
            ans+=g;
            g=f[i].cnt;
        }
    }
    printf("%lld\n",n-ans);
}
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ipt();
    init();
    solve();
    return 0;
}