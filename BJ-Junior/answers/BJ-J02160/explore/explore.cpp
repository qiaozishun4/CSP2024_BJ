#include<bits/stdc++.h>
using namespace std;
int xnent[4]={0,1,0,-1};
int ynent[4]={1,0,-1,0};
int sx,sy,d;
int n,m,k,t;
char s[1005][1005]={};
int ans=1;
void dfs(int x,int y,int d,int k){
    if(k==-1)return;
    for(int i = 0,j=d;i<4;i++,(++j)%4){
        if(k==-1)return;
        int x2=x+xnent[j],y2=y+ynent[j];
        if(x2<1||x2>n||y2<1||y2>m){k-=1;continue;}
        if(s[x2][y2]=='x'){continue;}
        ++ans;
        dfs(x2,y2,j,k-1);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>sx>>sy>>d;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        dfs(sx,sy,d,k);
        cout<<ans<<endl;
    }
    return 0;
}
