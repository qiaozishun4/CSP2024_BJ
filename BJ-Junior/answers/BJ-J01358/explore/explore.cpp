#include<bits/stdc++.h>
using namespace std;
int pkp[52];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
        cin>>n>>m>>k;
        int x,y,d,sum=1;
        cin>>x>>y>>d;
        x--;
        y--;
        char dt[n][m];
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>dt[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        while(k--){
            if(((x+dx[d])>=0 && (x+dx[d])<n) && ((y+dy[d])>=0 && (y+dy[d])<m) && (dt[x+dx[d]][y+dy[d]] != 'x')){
                x+=dx[d];
                y+=dy[d];
                if(vis[x][y]==0){
                    vis[x][y]=1;
                    sum++;
                }
            }
            else d=(d+1)%4;
        }
        cout<<sum;
        if(T>0) cout<<endl;
    }
    
    return 0;
}