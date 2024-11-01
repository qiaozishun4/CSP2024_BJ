#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
int n,m,k;
int ap[300030];
int a[300300];
vector<int>d[30];
int c[300300];
int e[10];
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
bool D[300300<<2];
int w[300300<<2],lim[300300<<2];
int siz[300300<<2];
int ssiz[300300<<2];
inline bool upd(int x){
    int pw=w[x],ps=siz[x];
    if(D[x]==0){
        if(w[lc(x)]==-1)w[x]=w[rc(x)],siz[x]=siz[lc(x)]+siz[rc(x)];
        else if(a[w[lc(x)]]<lim[x])w[x]=w[rc(x)],siz[x]=siz[rc(x)]+siz[lc(x)];
        else w[x]=w[lc(x)],siz[x]=siz[lc(x)];
    }
    else{
        siz[x]=siz[rc(x)];
        
        if(w[rc(x)]!=-1){
            if(a[w[rc(x)]]<lim[x])w[x]=w[lc(x)],siz[x]+=siz[lc(x)];
            else w[x]=w[rc(x)];
        }
        else w[x]=w[lc(x)],siz[x]+=siz[lc(x)];
    }
    return pw!=w[x]||ps!=siz[x];
}
int ANS[300030];
int l_g[300300<<2];
inline int S(int n){return n*(n+1)/2;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>ap[i];
    while((1<<k)<n)k++;

    for(int i=1;i<=m;i++)
    cin>>c[i];
    for(int i=1;i<=k;i++)
        for(int j=0;j<1<<(k-i);j++){
            char x;
            cin>>x;
            d[i].push_back(x-'0');
        }
    int K=1<<k;
    for(int i=1;i<=k;i++){
        int c=0;
        for(int j=0;j<K;j+=(1<<i)){
            D[(K+j)>>i]=d[i][c];
            lim[(K+j)>>i]=i;
            ssiz[(K+j)>>i]=S(j+(1<<i))-S(j);
            c++;
        }
        // assert(c==d[i].size());
    }
    for(int i=K;i<2*K;i++)
        ssiz[i]=i-K+1;
    l_g[0]=-1;
    for(int i=1;i<=K;i++){
        while((1<<l_g[i])<i+1)l_g[i]++;
        // cout<<i<<"x"<<l_g[i]<<endl;
    }
    int t;
    cin>>t;
    // for(int i=4;i<8;i++)
    // cout<<D[i]<<" ";
    // cout<<endl;
    
    while(t--){
        for(int i=0;i<4;i++)
        cin>>e[i];
        for(int i=0;i<n;i++)
            a[i]=ap[i]^e[(i+1)%4];
            // for(int i=0;i<n;i++)
            // cout<<a[i]<<" ";
            // cout<<endl;
        for(int i=1;i<2*K;i++)
            w[i]=-1,siz[i]=ssiz[i];
        ANS[0]=1;
        w[K]=0;
        siz[K]=0;
        for(int i=1;i<n;i++){
            w[K+i]=i;
            siz[K+i]=0;
            int p=l_g[i];
            int rt=(K+i)>>p;
            int x=K+i;
            // cout<<i<<" "<<K+i<<" "<<p<<" "<<rt<<endl;
        //    cout<<i<<" "<<rt<<endl;
        // cout<<
        // if(w[lc(264)]!=-1)
        //     cout<<w[lc(264)]<<" "<<w[rc(264)]<<" "<<D[264]<<" "<<lim[264]<<" "<<a[w[lc(264)]]<<endl;
            while(1){
                x>>=1;
                // cout<<"!"<<x<<endl;
                upd(x);
                if(x==rt)break;
                // if((!upd(x)&&l_g[i]==l_g[i-1])||x==rt)break;
            }
            ANS[i]=siz[rt];
            // cout<<lc(132)<<" "<<rc(132)<<" "<<w[lc(132)]<<" "<<w[rc(132)]<<endl;
            // cout<<i<<" "<<rt<<" "<<w[rt]<<" "<<siz[rt]<<endl;
            // for(int i=0;i<K;i++)
            //     cout<<w[K+i]<<"x"<<ay[K+i]<<" ";
            //     cout<<endl;
            if(w[rt]!=-1)ANS[i]+=w[rt]+1;
        }
        // for(int i=0;i<n;i++)
        // cout<<ANS[i]<<" ";
        // cout<<endl;
        int res=0;
        for(int i=1;i<=m;i++)
        res^=i*ANS[c[i]-1];
        cout<<res<<endl;
    }
    cout.flush();
    fflush(stdout);
    fclose(stdout);
    return 0;
}