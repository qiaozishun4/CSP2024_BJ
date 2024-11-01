#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn=2e5+7;
int n,k,q;
int L[maxn];
int SumL[maxn];
vector<int> S[maxn];
struct Edge{
    int v,w;
};
vector<Edge> E[maxn];
int a[maxn];
inline int Get(int i,int j){return SumL[i-1]+j+1;}
inline void Build(){
    for(int i=1;i<=n;i++)SumL[i]=SumL[i-1]+L[i];
    for(int i=1;i<=SumL[n];i++)E[i].clear();
    for(int i=1;i<=n;i++)for(int j=0;j<L[i];j++)a[Get(i,j)]=S[i][j];
    for(int i=1;i<=n;i++){
        for(int j=0;j<L[i];j++){
            for(int t=j+1;t<min(L[i],j+k);t++){
                E[Get(i,j)].push_back((Edge){Get(i,t),1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int t1=0;t1<L[i];t1++){
                for(int t2=0;t2<L[j];t2++){
                    if(S[i][t1]==S[j][t2]){
                        E[Get(i,t1)].push_back((Edge){Get(j,t2),0});
                        E[Get(j,t2)].push_back((Edge){Get(i,t1),0});
                    }
                }
            }
        }
    }
}
struct Stat{
    int p,len;
};
bool vis[maxn][22];
inline void Qry(int r,int c){
    queue<Stat> qu;
    while(!qu.empty())qu.pop();
    for(int i=1;i<=SumL[n];i++){
        if(a[i]==1){
            qu.push((Stat){i,0});
        }
        for(int j=0;j<=2*r-1;j++)vis[i][j]=0;
    }
    while(!qu.empty()){
        Stat u=qu.front();qu.pop();
        int p=u.p,l=u.len;
        if(vis[p][l])continue;
        vis[p][l]=1;
        if(l==r){
            if(a[p]==c){
                cout<<1<<endl;
                return;
            }
            continue;
        }
        for(auto e:E[p])qu.push((Stat){e.v,l+e.w});
    }
    cout<<0<<endl;
    return;
}
inline void slv(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>L[i];
        for(int j=1;j<=L[i];j++){
            int x;
            cin>>x;
            S[i].push_back(x);
        }
    }
    Build();
    while(q--){
        int r,c;
        cin>>r>>c;
        Qry(r,c);
    }
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T=0;
    cin>>T;
    while(T--)slv();
}