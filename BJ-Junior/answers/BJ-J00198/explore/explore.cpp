#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n>>m>>k>>x>>y>>d;
        char a[1005][1005];
        bool vis[1005][1005];
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        //do the motion,number is k
        for(int i=1;i<=k;i++){
            //1/0 I have gone there
            if(vis[x][y]==0){
                vis[x][y]=1;
                sum++;
            }
            //get the x`,y`
            int dx,dy;
            if(d==0){
                dx=x;
                dy=y+1;
            }else if(d==1){
                dx=x+1;
                dy=y;
            }else if(d==2){
                dx=x;
                dy=y-1;
            }else{
                dx=x-1;
                dy=y;
            }
            //1/0 I can go there
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]=='.'){
                x=dx;
                y=dy;
            }else{
                d=(d+1)%4;
            }
            //do it again
            if(vis[x][y]==0){
                vis[x][y]=1;
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
