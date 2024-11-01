//T2
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
const ll maxn=5e5+5;
ll T,n,L,m,V;
struct ca{
    ll d,v,a;
}cars[maxn];
ll dis[maxn];
namespace cod1{
    ll cnt[maxn],ans1,ans2;
    ll g[3005][3005];
    bool ischo[3005],ischao[3005];
    bool isend(){
        for(int i=1;i<=n;i++){
            if(ischao[i] && !ischo[i])return false;
        }
        return true;
    }
    void work(){
        memset(ischo,false,sizeof(ischo));
        memset(ischao,false,sizeof(ischao));
        memset(g,0,sizeof(g));
        ans1=ans2=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(dis[i]<cars[j].d)continue;
                if(V*V<cars[j].v*cars[j].v+2*cars[j].a*(dis[i]-cars[j].d)){
                    g[i][j]=1;
                    ischao[j]=true;
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                g[i][0]+=g[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            if(ischao[i])ans1++;
        }
        print(ans1);putchar(' ');
        while(!isend()){
            ll cur=-1,mx=0;
            for(int i=1;i<=m;i++){
                if(g[i][0]>mx){
                    mx=g[i][0];
                    cur=i;
                }
            }
            ans2++;
            for(int i=1;i<=n;i++){
                if(!g[cur][i])continue;
                ischo[i]=true;
                for(int j=1;j<=m;j++){
                    if(g[j][i]){
                        g[j][i]=0;
                        g[j][0]--;
                    }
                }
            }
        }
        print(m-ans2);putchar('\n');
    }
}
ll maxna,minna,bigl;
namespace cod2{
    void work(){
        ll ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(cars[i].v>V && cars[i].d<=bigl)ans1++;
        }
        if(ans1==0){
            print(ans1);putchar(' ');print(m);putchar('\n');
        }else{
            print(ans1);putchar(' ');print(m-1);putchar('\n');
        }
    }
}
namespace cod3{
    void work(){
        ll ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(V*V<cars[i].v*cars[i].v+2*cars[i].a*(bigl-cars[i].d))ans1++;
        }
        if(ans1==0){
            print(ans1);putchar(' ');print(m);putchar('\n');
        }else{
            print(ans1);putchar(' ');print(m-1);putchar('\n');
        }
    }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T=read();
    while(T--){
        n=read();m=read();L=read();V=read();
        maxna=0;
        minna=1e18;
        bigl=0;
        for(int i=1;i<=n;i++){
            cars[i].d=read();cars[i].v=read();cars[i].a=read();
            maxna=max(maxna,cars[i].a);
            minna=min(minna,cars[i].a);
        }
        for(int i=1;i<=m;i++){
            dis[i]=read();
            bigl=max(bigl,dis[i]);
        }
        if(maxna==0){
            cod2::work();
        }else if(n<=3005 && m<=3005){
            cod1::work();
        }else if(minna>0){
            cod3::work();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
