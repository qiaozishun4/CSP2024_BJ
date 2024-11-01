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
int n,m,T,K;
long long A0[1<<17],a[1<<17],C[1<<17];
bool opt[17][1<<17];
struct T{
    int dep,trn;
    int cer,f;
}t[1<<19];
int ls(int x){return x<<1;}
int rs(int x){return (x<<1)|1;}
int lnk[1<<17];
void init_t(int rt,int dep,int trn){
    t[rt].dep=dep,t[rt].trn=trn,t[rt].cer=-1,t[rt].f=1<<dep;
    if(!dep){
        lnk[trn]=rt;
        t[rt].f=trn+1;
        return;
    }
    trn<<=1,dep--;
    init_t(ls(rt),dep,trn);
    init_t(rs(rt),dep,trn+1);
    t[rt].f=t[ls(rt)].f+t[rs(rt)].f;
}
void push_up(int rt){
    if(!opt[t[rt].dep-1][t[rt].trn]){
        if(t[ls(rt)].cer<0){
            // puts("!!!");
            t[rt].cer=t[rs(rt)].cer,t[rt].f=t[ls(rt)].f+t[rs(rt)].f;
        }
        else{
            if(a[t[ls(rt)].cer]>=t[rt].dep){
                // cout<<t[ls(rt)].cer<<" "<<t[ls(rt)].f<<endl;
                t[rt].cer=t[ls(rt)].cer,t[rt].f=t[ls(rt)].f;
                if(t[ls(rt)].f) t[rt].f+=t[rs(rt)].f;
            }
            else{
                t[rt].cer=t[rs(rt)].cer,t[rt].f=t[ls(rt)].f+t[rs(rt)].f;
        // cout<<t[rt].dep<<" "<<t[rt].cer<<" "<<t[rt].f<<endl;
            }
        }
    }
    else{
        if(t[rs(rt)].cer<0){
            t[rt].cer=t[ls(rt)].cer,t[rt].f=t[rs(rt)].f+t[ls(rt)].f;
        }
        else{
            if(a[t[rs(rt)].cer]>=t[rt].dep){
                t[rt].cer=t[rs(rt)].cer,t[rt].f=t[rs(rt)].f;
                if(t[rs(rt)].f) t[rt].f+=t[ls(rt)].f;
            }
            else{
                t[rt].cer=t[ls(rt)].cer,t[rt].f=t[rs(rt)].f+t[ls(rt)].f;
            }
        }
    }
}
void change(int rt){
    if(!t[rt].dep){
        t[rt].cer=t[rt].trn,t[rt].f=0;
        change(rt>>1);
        return;
    }
    push_up(rt);
    if(rt>1) change(rt>>1);
}
int ans[1<<17];
void solve(){
    init_t(1,K,0);
    // for(int i=0;i<n;i++) if(a[i]<=20) cout<<a[i]<<" "; cout<<endl;
    for(int i=0;i<n;i++){
        change(lnk[i]);
        int pos=1;
        for(;(1<<t[pos].dep)/2>=i+1;pos=ls(pos));
        ans[i]=t[pos].f+(t[pos].cer>=0)*(t[pos].cer+1);
        // if(i+1==(1<<t[pos].dep))
        // cout<<t[pos].dep<<" "<<t[pos].f<<" "<<t[pos].cer<<endl;
        // cout<<ans[i]<<endl;
    }
    // cout<<endl;
    long long ANS=0;
    for(int i=1;i<=m;i++){
        ANS^=1ll*i*ans[C[i]];
        // cout<<ANS<<" "<<i*ans[C[i]]<<endl;
    }
    cout<<ANS<<endl;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) A0[i]=read();
    for(int i=1;i<=m;i++) C[i]=read()-1;
    for(K=0;(1<<K)<n;K++);
    for(int i=K-1;i>=0;i--){
        for(int j=0;j<(1<<i);j++){
            char c=getchar();
            for(;c!='0'&&c!='1';c=getchar());
            opt[K-1-i][j]=c-'0';
            // if(opt[i][j]) puts("!!!");
        }
    }
    cin>>T;
    while(T--){
        long long X[10];
        for(int i=0;i<4;i++) X[i]=read();
        // cout<<X[0]<<" "<<X[1]<<endl;
        for(int i=0;i<n;i++) a[i]=A0[i]^X[(i+1)%4];
        solve();
    }
    return 0;
}