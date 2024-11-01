//T4 15pts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
ll T,n,k,q,m,xx;
vector<ll> arr[maxn];
namespace cod1{
    vector<ll> gra[maxn];
    bool vis[500015];
    struct point{
        ll fa,num,step;
    };
    void pstt(point x){
        printf("fa=%lld,num=%lld,step=%lld\n",x.fa,x.num,x.step);
    }
    queue<point> qu;
    ll hsh(point x){
        return abs(((x.fa*2007*2007)+(x.num*2007)+x.step)%500003)%500003;
    }
    bool bfs(ll ed,ll sp){
        while(!qu.empty())qu.pop();
        memset(vis,false,sizeof(vis));
        qu.push((point){-1,1,0});
        while(!qu.empty()){
            point fa=qu.front();
            qu.pop();
     //      pstt(fa);
            if(fa.step>sp)continue;
            if(fa.num==ed && fa.step==sp){
                return true;
            }
            if(!vis[hsh(fa)]){
                vis[hsh(fa)]=true;
            }else{
                continue;
            }
            for(int i=1;i<=n;i++){
                if(i==fa.fa)continue;
                ll siz=arr[i].size(),pri=1e9,ppri=1e9;
 //               print(fa.num);putchar('\n');
                for(int j=0;j<siz;j++){
                    if(arr[i][j]==fa.num){
                        ppri=pri;
                        pri=j;
 //                       print(pri);putchar(' ');
                    }
                    if((j-pri>0 && j-pri+1<=k || j-ppri>0 && j-ppri+1<=k)&& pri!=-1){
                        qu.push((point){i,arr[i][j],fa.step+1});
                    }
                }
 //               putchar('\n');
            }
        }
        return false;
    }
    void work(){
        for(int i=1;i<=q;i++){
            ll r=read(),c=read();
            if(bfs(c,r)){
                print(1);
            }else{
                print(0);
            }
            putchar('\n');
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    T=read();
    while(T--){
        for(int i=0;i<=n;i++){
            arr[i].clear();
        }
        n=read();k=read();q=read();
        ll mxnum=0;
        for(int i=1;i<=n;i++){
            m=read();
            for(int j=1;j<=m;j++){
                xx=read();
                arr[i].push_back(xx);
                mxnum=max(mxnum,xx);
            }
        }
        if(n<=1000)cod1::work();
        else for(int i=1;i<=m;i++){
            printf("0\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
