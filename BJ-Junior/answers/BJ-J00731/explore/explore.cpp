#include<iostream>
#include<cstdio>
using namespace std;
int T;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n=0,m=0,k=0,d=0,x=0,y=0;
        char maps[1001][1001]={};
        bool vis[1001][1001]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>maps[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            if(d==0){
                if(y+1>=1&&y+1<=m&&maps[x][y+1]=='.'){
                    vis[x][y+1]=1;
                    y=y+1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(x+1>=1&&x+1<=n&&maps[x+1][y]=='.'){
                    vis[x+1][y]=1;
                    x=x+1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==2){
                if(y-1>=1&&y-1<=m&&maps[x][y-1]=='.'){
                    vis[x][y-1]=1;
                    y=y-1;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==3){
                if(x-1>=1&&x-1<=n&&maps[x-1][y]=='.'){
                    vis[x-1][y]=1;
                    x=x-1;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
