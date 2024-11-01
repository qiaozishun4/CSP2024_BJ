#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int k,d[8][2]={{0,1},{1,0},{0,-1},{-1,0},{0,1},{1,0},{0,-1},{-1,0}},sum=1;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y,nowd;
        cin>>n>>m>>k;
        cin>>x>>y>>nowd;
        sum=1;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
        mp[x][y]='#';
        while(k--){
            if(x+d[nowd][0]<1||x+d[nowd][0]>n||y+d[nowd][1]<1||y+d[nowd][1]>m||mp[x+d[nowd][0]][y+d[nowd][1]]=='x'){
                nowd=(nowd+1)%4;
                continue;
            }
            else{
                x+=d[nowd][0];
                y+=d[nowd][1];
                if(mp[x][y]=='.'){
                    sum++;
                    mp[x][y]='#';
                }
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
