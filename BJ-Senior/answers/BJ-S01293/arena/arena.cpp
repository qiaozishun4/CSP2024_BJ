#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<random>
#define use_freopen
//#define use_debug
using namespace std;
const int N=2e5+5,L=log2(N)+5,NN=(1<<(int(log2(N)+1)))+5;
int n,m,atemp[N],c[N],k_static,gamble[L][NN],T_trash,k[N],a[N],oval[L][NN];
int xtemp[N];
int dfs(int k,int has,int line/*winner must be over else return zero*/,int pos)
{
    /*if(k==0) return 1;//able to win
    int basic_line=((pos-1)<<level)+1;
    if(usecnt-basic_line<=0) return 1<<k;//you can decide randomly
    int gamb=gamble[k][pos];
    if(gamb==0)
    {
        if()
    }*/
    return 1;
}
int main()
{
    #ifdef use_freopen
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    #endif
    #ifdef use_debug
    freopen("/home/rdfz/CSP-S/arena/arena1.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>atemp[i];
    for(int i=1;i<=m;i++){
        cin>>c[i];
        k[i]=int(log2(c[i]-1))+1;
    }
    k_static=int(log2(n-1))+1;
    for(int i=1;i<=k_static;i++)
        for(int j=1;j<=(1<<(k_static-i));j++)
        {
            char cc;
            cin>>cc;
            gamble[i][j]=cc-'0';
        }
    cin>>T_trash;
    while(T_trash--)
    {
        cin>>xtemp[0]>>xtemp[1]>>xtemp[2]>>xtemp[3];
        for(int i=1;i<=n;i++)
            a[i]=atemp[i]^xtemp[i%4];
        for(int i=1;i<=n;i++) oval[0][i]=a[i];
        for(int i=n+1;i<=(1<<k_static);i++) oval[0][i]=-1;
        /*for(int i=1;i<=k_static;i++)
            for(int j=1;j<=(1<<(k_static-i));j++)
                if(oval[i-1][j*2+1]!=-1)
                    if(gamble[i][j])
                        if(oval[i-1][j*2+1]>=)*/
        long long ans=0;
        for(int i=1;i<=m;i++)
            ans=ans^(i*dfs(k[i],c[i],0,1));
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}
