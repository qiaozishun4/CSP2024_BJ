#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int mapp[N][N];

const int F[4][2]={{0,+1},{+1,0},{0,-1},{-1,0}};

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(mapp,0,sizeof(mapp));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            char s[N];
            scanf("%s",s+1);
            for(int j=1;j<=m;j++){
                if(s[j]=='.'){
                    mapp[i][j]=1;
                }else if(s[j]=='x'){
                    mapp[i][j]=0;
                }
            }
        }
        set< pair<int,int> > se;
        se.clear();
        se.insert({x,y});
        for(int i=1;i<=k;i++){
            int tx=x+F[d][0];
            int ty=y+F[d][1];
            if(mapp[tx][ty]){
                x=tx;
                y=ty;
                se.insert({x,y});
            }else{
                d=(d+1)%4;
            }
        }
        printf("%d\n",se.size());
    }
    return 0;
}
