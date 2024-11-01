#include<bits/stdc++.h>
using namespace std;
int x,y,step,sx,sy,sd,cnt=1,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char dt[1005][1005];
int vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        cin>>x>>y>>step>>sx>>sy>>sd;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++)cin>>dt[i][j];
        }
        vis[sx][sy]=n+1;
        while(step--){
            if(sx+dir[sd][0]>=1&&sx+dir[sd][0]<=x&&sy+dir[sd][1]>=1&&sy+dir[sd][1]<=y&&dt[sx+dir[sd][0]][sy+dir[sd][1]]=='.'){
                sx+=dir[sd][0];
                sy+=dir[sd][1];
                if(vis[sx][sy]!=n+1){
                    cnt++;
                    vis[sx][sy]=n+1;
                }
            }
            else{
                sd++;
                sd%=4;
            }
        }
        cout<<cnt<<endl;
        cnt=1;
    }
    return 0;
}
