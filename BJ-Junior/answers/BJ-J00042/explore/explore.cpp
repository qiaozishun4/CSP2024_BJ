#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char xxx;
int dd[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int tmap[1010][1010];
int rmap[1010][1010];
int cnt=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cnt=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>xxx;
                if(xxx=='.'){
                    tmap[i][j]=0;
                }else{
                    tmap[i][j]=1;
                }
                rmap[i][j]=0;
            }
        }
        for(int i=0;i<=n+1;i++){
            tmap[i][0]=1;
            tmap[i][m+1]=1;
        }
        for(int i=0;i<=m+1;i++){
            tmap[0][i]=1;
            tmap[n+1][i]=1;
        }
        rmap[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=x+dd[d][0];
            int ny=y+dd[d][1];
            if(tmap[nx][ny]==0){
                if(rmap[nx][ny]==0)cnt++;
                rmap[nx][ny]=1;
                x=nx;
                y=ny;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
