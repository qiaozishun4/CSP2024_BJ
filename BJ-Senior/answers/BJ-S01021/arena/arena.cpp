//T4
#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar((x%10)^48);
}
const ll maxn=2e5+5;
ll n,m,base[maxn],req[maxn],knowl[maxn],T;
char ch[32][maxn];
namespace cod1{
    ll dpp[32][maxn],lg,len;
    bool unk[32][maxn];
    ll cal(ll ci){
        memset(dpp,0,sizeof(dpp));
        lg=log2(ci)+1;
        if(1<<(lg-1)==ci)lg--;
        ll len=ci;
        for(int i=1;i<=len;i++){
            dpp[1][i]=i;
        }
        for(int i=1;i<=lg;i++){
            for(int j=1;j<=len/2;j++){
                if(ch[i][j]=='1' && knowl[dpp[i-1][j*2+1]]>i){
                    dpp[i][j]=dpp[i-1][j*2+1];
                }else if(ch[i][j]=='2' && knowl[dpp[i-1][j*2]]>i){
                    dpp[i][j]=dpp[i-1][j*2];
                }
            }
            len>>=1;
        }
        return dpp[lg][1];
    }
    void work(){
        ll ans=0;
        for(int i=1;i<=m;i++){
            ans^=(cal(req[i])*i);
        }
        print(ans);
    }
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    bool is2p=true;
    n=read();m=read();
    for(int i=1;i<=n;i++){
        base[i]=read();
    }
    for(int i=1;i<=m;i++){
        req[i]=read();
        ll lg=log2(req[i]);
        if(1<<lg!=req[i])is2p=false;
    }
    ll lg=log2(n)+1;
    if(1<<(lg-1)==n)lg--;
    for(int i=1;i<=lg;i++){
        scanf("%s",ch[i]+1);
    }
    T=read();
    while(T--){
        ll ar[4]={read(),read(),read(),read()};
        for(int i=1;i<=n;i++){
            knowl[i]=base[i]^ar[(i%4)];
        }
        cod1::work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
