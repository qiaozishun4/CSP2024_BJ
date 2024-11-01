#include<iostream>
using namespace std;
int t,n,m,k,x0,y0,d0;
char dt[1010][1010];
int dfs(int x,int y,int d,int cnt,int k){
    int nextx,nexty;
    if(k==0){
        return cnt;
    }
    if(d==0){
        nextx=x;
        nexty=y+1;
    }else if(d==1){
        nextx=x+1;
        nexty=y;
    }else if(d==2){
        nextx=x;
        nexty=y-1;
    }else if(d==3){
        nextx=x-1;
        nexty=y;
    }
    if(1<=nextx&&nextx<=n&&1<=nexty&&nexty<=m&&dt[nextx][nexty]=='.'){
        dfs(nextx,nexty,d,cnt+1,k-1);
    }else{
        dfs(x,y,(d+1)%4,cnt,k-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
            }
        }
        cout<<dfs(x0,y0,d0,1,k)<<endl;
    }
    return 0;
}
