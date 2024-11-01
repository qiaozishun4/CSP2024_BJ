#include<bits/stdc++.h>

using ll=long long;

int read(){
    int res=0; char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48),c=getchar();
    return res;
}

#define MAXN 200005
#define MAXA 1000005

int n;
int now[MAXA],pre[MAXN];
ll a[MAXN],f[MAXN],g[MAXA],fc,ans=0;

void run(){
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    int p=0; ans=fc=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[p]) ans+=a[i];
        else a[++p]=a[i];
    }
    memset(now,-1,sizeof(now));
    memset(f,0,sizeof(f));
    memset(g,-0x3f,sizeof(g));
    for(int i=1;i<=p;i++){
        pre[i]=now[a[i]];
        now[a[i]]=i;
    }
    for(int i=1;i<=p-1;i++){
        f[i]=std::max(g[a[i+1]]+a[i+1],fc);
        fc=std::max(fc,f[i]);
        g[a[i]]=std::max(g[a[i]],f[i]);
    }
    std::cout<<fc+ans<<'\n';

    return;
}

int T;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    T=read();
    for(int i=1;i<=T;i++) run();

    return 0;
}