#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,s,h;
vector<int>v[N];
vector<int>c[N];
int f[105][N];
int p[105][N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&s);
        for(int i=0;i<N;++i){
            v[i].clear();
            c[i].clear();
            for(int j=0;j<=100;++j){
                f[j][i]=0;
                p[j][i]=0;
            }
        }
        h=0;
        for(int i=1;i<=n;++i){
            int x,y;
            scanf("%d",&x);
            for(int j=1;j<=x;++j){
                scanf("%d",&y);
                v[i].push_back(y);
                ++h;
                c[y].push_back(h);
                if(y==1){
                    f[0][h]=1;
                }
            }
        }
        for(int i=0;i<100;++i){
            h=0;
            for(int j=1;j<=n;++j){
                for(int k=0;k<v[j].size();++k){
                    ++h;
                    if(f[i][h]==1){
                        for(int l=1;(k+l<v[j].size())&&(l<m);++l){
                            ++p[i+1][v[j][k+l]];
                            f[i+1][h+l]=-1;
                        }
                    }
                }
            }
            for(int j=1;j<=2e5;++j){
                if(p[i+1][j]>1){
                    for(int k=0;k<c[j].size();++k){
                        f[i+1][c[j][k]]=1;
                    }
                }
                if(p[i+1][j]==1){
                    for(int k=0;k<c[j].size();++k){
                        if(f[i+1][c[j][k]]==-1){
                            f[i+1][c[j][k]]=0;
                            continue;
                        }
                        f[i+1][c[j][k]]=1;
                    }
                }
            }
        }
        for(int i=1;i<=s;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",p[x][y]!=0);
        }
    }
    return 0;
}