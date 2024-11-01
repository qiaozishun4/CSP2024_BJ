#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c<'0'||c>'9');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
long double eps=1e-9;
int eq(long double x,long double y){
    if(abs(x-y)<=eps) return 0;  if(x>y) return 1;  return -1;
}
int n,m,L,V;
long double Ek;
struct carr{
    int d,v,a;
    int l,r,ck;
    void get_seq(){
        l=r=ck=0;
        if(a==0){
            if(v<=V) ck=-1; else l=d,r=L;
            return;
        }
        if(a>0){
            if(v>V){
                l=d,r=L;
                return;
            } 
            long double ek=v*v; ek/=2;
            long double x=(Ek-ek)/a;
            int x0=x;
            l=d+x0+1,r=L;
            if(l>r) ck=-1;
        }
        else{
            if(v<=V){
                ck=-1;
                return;
            }
            long double ek=v*v; ek/=2;
            long double x=(Ek-ek)/a;
            int x0=x; if(eq(x,x0)==0) x0--;
            l=d,r=min(d+x0,L);
            // cout<<l<<" "<<r<<endl;
        }
    }
}c[100005];
int b[100005],p0[1000006],p1[1000006];
int lst[1000006],nxt[1000006];
vector<int> vec[1000006];
void solve(){
    cin>>n>>m>>L>>V; L++;
    Ek=V;Ek*=V;Ek/=2;
    for(int i=0;i<=L;i++) p0[i]=p1[i]=0;
    for(int i=1;i<=n;i++){
        c[i].d=read()+1,c[i].v=read(),c[i].a=read();
        c[i].get_seq();
    }
    // return ;
    for(int i=1;i<=m;i++) b[i]=read()+1,p0[b[i]]=1;
    for(int i=1;i<=L;i++) p1[i]=p1[i-1]+p0[i];
    sort(b+1,b+m+1);
    for(int i=n;i;i--){
        if(c[i].ck<0) swap(c[i],c[n]),n--;
    }
    for(int i=1;i<=n;i++){
        if(p1[c[i].r]-p1[c[i].l-1]) c[i].ck=1;
    }
    for(int i=n;i;i--) if(!c[i].ck) swap(c[i],c[n]),n--;
    cout<<n<<" ";
    lst[0]=0; for(int i=1;i<=L;i++) lst[i]=p0[i]?i:lst[i-1];
    nxt[L+1]=L+1; for(int i=L;i;i--) nxt[i]=p0[i]?i:nxt[i+1];
    for(int i=1;i<=n;i++) c[i].l=nxt[c[i].l],c[i].r=lst[c[i].r];
    for(int i=0;i<=L;i++) vec[i].clear();
    for(int i=1;i<=n;i++) vec[c[i].l].push_back(c[i].r);
    int ans=0,mn=1e9;
    for(int i=0;i<=L;i++){
        for(int j=0;j<vec[i].size();j++) mn=min(mn,vec[i][j]);
        if(mn==i) ans++,mn=1e9;
    }
    if(mn<=L) ans++;
    cout<<m-ans<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}