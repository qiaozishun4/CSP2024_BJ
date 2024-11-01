#include<bits/stdc++.h>

using ll=long long;

int read(){
    int res=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
    return res;
}
int read1(){
    int res=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    res=(res<<3)+(res<<1)+(c^48);
    return res;
}

#define MAXN 200005

int n,m;
char r[MAXN];
int d[20][MAXN];
int w[20][MAXN];
int a0[MAXN],a[MAXN],x[4];
int c[MAXN];
ll ans[MAXN],a1[MAXN],ac;
int T,lvl;

void calc(int l,int r,int k){
    if(k==0){
        w[k][l]=l;
        return;
    }
    int mid=(l+r)>>1;
    calc(l,mid,k-1),calc(mid+1,r,k-1);
    int x=d[k][l>>k];
    if(a[w[k-1][(l>>(k-1))^x]]>=k){
        w[k][(l>>k)]=w[k-1][(l>>(k-1))^x];
    }else{
        w[k][(l>>k)]=w[k-1][(l>>(k-1))^x^1];
    }
    if(l==1){
        ans[(1<<k)]=w[k][(l>>k)];
    }
    return;
}

void run(){
    x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
    calc(1,(1<<lvl),lvl); ac=0;
    for(int i=1;i<=m;i++){
        ac^=(ll)i*ans[1<<c[i]];
    }
    std::cout<<ac<<'\n';
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) c[i]=read();
    for(int i=1;i<=n;i<<=1,lvl++);
    for(int i=1;i<=lvl;i++){
        for(int j=0;j<(1<<(lvl-i));j++){
            d[i][j]=read1();
        }
    }
    T=read();
    for(int i=1;i<=T;i++) run();
    return 0;
}