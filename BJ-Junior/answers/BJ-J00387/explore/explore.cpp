#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int t,n,m,k,sx,sy,sd;
void dfs(int x,int y,int d,int k,int cnt){
    if(k==0){
        cout<<cnt<<endl;
        return;
    }
    int nextx=x,nexty=y;
    if(d==0){
        nexty++;
    }else if(d==1){
        nextx++;
    }else if(d==2){
        nexty--;
    }else{
        nextx--;
    }
    if(nextx<=0 || nextx>n || nexty<=0 || nexty>m || a[nextx][nexty]=='x'){
        dfs(x,y,(d+1)%4,k-1,cnt);
        return;
    }else{
        if(vis[nextx][nexty]==0){
            vis[nextx][nexty]=1;
            cnt++;
        }
        dfs(nextx,nexty,d,k-1,cnt);
        return;
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>sx>>sy>>sd;
        string ss;
        for(int i=1;i<=n;i++){
            cin>>ss;
            for(int j=1;j<=m;j++){
                a[i][j]=ss[j-1];
            }
        }
        memset(vis,0,sizeof vis);
        vis[sx][sy]=1;
        dfs(sx,sy,sd,k,1);
    }
    return 0;
}
