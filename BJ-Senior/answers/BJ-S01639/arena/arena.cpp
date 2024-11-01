/*
好吧，我宣布阿克失败了。

太难写了/fn/fn/fn

又是被喂答辩的一天。
*/
#include<stdio.h>
#include<vector>
int n,m,k,tot,a[100001],c[100001],d[200001];
int flag[400001];long long res[100001];
std::vector<int>f[400001];
void fill(int u){
    flag[u]=1;
    if((u<<1)<tot)fill(u<<1),fill(u<<1|1);
}
void work(){
    int x[4];
    scanf("%d%d%d%d",x,x+1,x+2,x+3);
    for(int i=1;i<=n;++i)a[i]^=x[i&3];
    for(int i=1;i<=(1<<k);++i)flag[i+(1<<k)-1]=1,f[i+(1<<k)-1]={i};
    for(int i=1<<k;--i;){
        flag[i]=1;
        f[i].clear();
        for(const auto&x:f[i<<1])f[i].push_back(x);
        for(const auto&x:f[i<<1|1])f[i].push_back(x);
    }
    for(int i=1,root=(1<<k),L=1;i<=n;++i){
        int u=(1<<k)+i-1;
        for(int l=1;u>root;u>>=1,++l)
            if(d[u>>1]){
                if(u&1){
                    if(f[u].size()>1||f[u][0]>i){
                        f[u>>1].clear();
                        for(const auto&x:f[u])if(x>i||a[x]>=l)f[u>>1].push_back(x);
                        for(const auto&x:f[u^1])f[u>>1].push_back(x);
                    }else if(a[f[u][0]]>=l)f[u>>1]=f[u];
                    else f[u>>1]=f[u^1];
                }else{
                    f[u>>1].clear();
                    for(const auto&x:f[u])f[u>>1].push_back(x);
                    for(const auto&x:f[u^1])f[u>>1].push_back(x);
                }
            }else{
                if(u&1){
                    if(a[f[u^1][0]]<l)f[u>>1]=f[u];
                }else{
                    if(f[u].size()>1||f[u][0]>i){
                        f[u>>1].clear();
                        for(const auto&x:f[u])if(x>i||a[x]>=l)f[u>>1].push_back(x);
                        for(const auto&x:f[u^1])f[u>>1].push_back(x);
                    }else if(a[f[u][0]]>=l)f[u>>1]=f[u];
                    else f[u>>1]=f[u^1];
                }
            }
        res[i]=0;
        for(const auto&x:f[root])res[i]+=x;
        if((i&(-i))==i&&root>1){
            f[root>>1]=f[root^1];
            for(const auto&x:f[root])if(a[x]>=L)f[root>>1].push_back(x);
            root>>=1,++L;
        }
    }
    /*
    for(int i=1,root=(1<<k);i<=n;++i){
        int u=(1<<k)+i-1;
        for(int l=0;u>root;u>>=1,++l){
            if(d[u>>1])f[u]=0;
            else f[u]=l;
            if(u&1)break;
        }u>>=1;
        if(d[u])
    }
    */
    long long RES=0;
    for(int i=1;i<=m;++i)RES^=res[c[i]]*i;
    printf("%lld\n",RES);
    for(int i=1;i<=n;++i)a[i]^=x[i&3];
}
int main(){
    freopen("arena.in","r",stdin),freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1,x;i<=m;++i)scanf("%d",c+i);
    for(k=0;(1<<k)<n;++k);
    for(int i=1;i<=k;++i)
        for(int len=1<<(k-i),id=1<<(i-1);len--;)
            scanf("%1d",d+(id++));
    tot=(1<<(k+1))-1;
    int t;
    for(scanf("%d",&t);t--;work());
    return 0;
}