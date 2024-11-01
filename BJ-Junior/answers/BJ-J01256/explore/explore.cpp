#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int n,m,k,x,y,d;
    int ans[t];
    for(int cycle=0;cycle<t;cycle++){
        cin>>n>>m>>k>>x>>y>>d;
        char map[n+1][m+1];
        bool road[n+1][m+1]={0};
        road[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
            }
        }
        ans[cycle]=1;
        for(int i=0;i<k;i++){
            if(d==0){
                if(y+1<=m&&map[x][y+1]!='x'){
                    y++;
                    if(road[x][y]==0){
                        road[x][y]=1;
                        ans[cycle]++;
                    }
                }else{
                    d++;
                }
            }else if(d==1){
                if(x+1<=n&&map[x+1][y]!='x'){
                    x++;
                    if(road[x][y]==0){
                        road[x][y]=1;
                        ans[cycle]++;
                    }
                }else{
                    d++;
                }
            }else if(d==2){
                if(y-1>0&&map[x][y-1]!='x'){
                    y--;
                    if(road[x][y]==0){
                        road[x][y]=1;
                        ans[cycle]++;
                    }
                }else{
                    d++;
                }
            }else if(d==3){
                if(x-1>0&&map[x-1][y]!='x'){
                    x--;
                    if(road[x][y]==0){
                        road[x][y]=1;
                        ans[cycle]++;
                    }
                }else{
                    d=0;
                }
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
