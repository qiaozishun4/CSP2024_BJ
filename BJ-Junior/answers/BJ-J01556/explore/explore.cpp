#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,ax,ay,az;
char a[10][1000][1000];
int dx[10]={1,0,-1,0},dy[10]={0,1,0,-1};
void ans(int s,int n,int m,int k,int ax,int ay,int az){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[s][i][j];
    }
    if(az==0){
        if(ax+dx[1]<=n&&ay+dy[1]<=m) cout<<1<<endl;
        else return;
    }
    if(az==1){
        if(ax+dx[0]<=n&&ay+dy[0]<=m) cout<<1<<endl;
        else return;
    }
    if(az==2){
        if(ax+dx[3]<=n&&ay+dy[3]<=m) cout<<1<<endl;
        else return;
    }
    if(az==3){
        if(ax+dx[2]<=n&&ay+dy[2]<=m) cout<<1<<endl;
        else return;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t>>n>>m>>k>>ax>>ay>>az;
    for(int i=1;i<=t;i++)
        ans(i,n,m,k,ax,ay,az);
    return 0;
}
