#include<bits/stdc++.h>
using namespace std;long long n,m,k;long long a,b,c;char mmm[1005][1005];
long long wwy[5][3]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1005][1005];
long long dfs(long long aa,long long bb,long long cc){
    long long ans=0;
    for(long long j=1;j<=k;j++){

        if(1<=aa+wwy[cc][0]&&aa+wwy[cc][0]<=n&&1<=bb+wwy[cc][1]&&bb+wwy[cc][1]<=m&&mmm[aa+wwy[cc][0]][bb+wwy[cc][1]]=='.'){
            aa+=wwy[cc][0];bb+=wwy[cc][1];
            if(vis[aa][bb]==0){ans++;
            vis[aa][bb]=1;
            }

        }
        else{
            cc=(cc+1)%4;
        }

    }
    return ans;
}
long long xia=0;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long anss[10];

    long long t;cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cin>>n>>m>>k;

        cin>>a>>b>>c;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>mmm[i][j];
            }
        }
        vis[a][b]=1;
        anss[++xia]=dfs(a,b,c)+1;
    }
    for(long long i=1;i<=xia;i++){
        cout<<anss[i]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
