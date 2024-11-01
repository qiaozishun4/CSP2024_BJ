#include<bits/stdc++.h>
using namespace std;

int T;
int n,k,q,m=0,r,c;
vector<int>v[100005];
vector<int>xx[2000005];
vector<int>yy[2000005];
int l;
vector<int>b[200005][105];

bool check(int f,int g,int h,int j){
    for(int i=0;i<b[v[f][g]][h].size();++i){
        if(b[v[f][g]][h][i]==j) return 0;
    }
    return 1;
}

void dfs(int s,int x,int y){
    if(s>100){
        return;
    }
    int nj=((y+k>v[x].size())?(v[x].size()):(y+k));
    for(int j=y+1;j<nj;++j){
        if(check(x,j,s,x)){
            b[v[x][j]][s].push_back(x);
            for(int i=0;i<xx[v[x][j]].size();++i){
                if(xx[v[x][j]][i]!=x)dfs(s+1,xx[v[x][j]][i],yy[v[x][j]][i]);
                //else cout<<v[x][y]<<" "<<x<<" "<<y<<" "<<v[x][j]<<" "<<xx[v[x][j]][i]<<" "<<yy[v[x][j]][i]<<"\n";
            }
        }
    }
    return;
}

void mian(){
    for(int i=0;i<=n;++i){
        v[i].clear();
    }
    for(int i=0;i<=m;++i){
        xx[i].clear();
        yy[i].clear();
        for(int j=0;j<=100;++j){
            b[i][j].clear();
        }
    }
    n=k=q=m=r=c=l=0;
    cin>>n>>k>>q;
    for(int i=0;i<n;++i){
        cin>>l;
        for(int j=0;j<l;++j){
            int z;
            cin>>z;
            xx[z].push_back(i);
            yy[z].push_back(j);
            v[i].push_back(z);
        }
        m=max(m,l);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<v[i].size();++j){
            if(v[i][j]==1){
                dfs(1,i,j);
            }
        }
    }
    for(int i=0;i<q;++i){
        cin>>r>>c;
        cout<<(!b[c][r].empty())<<"\n";
    }
    return;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        mian();
    }
    return 0;
}
