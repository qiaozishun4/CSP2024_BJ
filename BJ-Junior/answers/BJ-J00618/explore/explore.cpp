#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k,x,y,d;
char a[1001][1001];
int f(int x,int y,int d,int step,int cnt){
    if(cnt>k){
        if(!(/*(!a[x][y]=='x')&&*/x<=n&&y<=m&&x>0&&y>0)){cout<<a[x][y];step--;}
        return step;
    }
    a[x][y]='?';
    int x1=x+dx[d],y1=y+dy[d];
    //cout<<x1<<' '<<y1<<' '<<step<<' '<<cnt<<endl;
    if(a[x1][y1]=='.'&&x1<=n&&y1<=m&&x1>0&&y1>0){
        if(a[x1][y1]=='?') step--;
        return f(x1,y1,d,step+1,cnt+1);
    }else{
        return f(x,y,(d+1)%4,step,cnt+1);
    }
    //return step;
}
int main(){
freopen("explore.in","r",stdin);
freopen("explore.out","w",stdout);
int t;
cin>>t;
for(int u=1;u<=t;u++){
    //char a[1001][1001]
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    cout<<f(x,y,d,1,1)<<endl;
}

return 0;
}
