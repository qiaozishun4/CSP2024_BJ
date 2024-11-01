#include<bits/stdc++.h>
using namespace std;
int d[4][2]={0,1,1,0,0,-1,-1,0};
char a[1010][1010];
bool vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        int n,m,k;
        cin>>n>>m>>k;
        int sx,sy,sd;
        cin>>sx>>sy>>sd;
        vis[sx][sy]=1;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                a[i][j]=s[j-1];
            }
        }
        for(int i=1;i<=k;i++){
            int xx=sx+d[sd][0];
            int yy=sy+d[sd][1];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='x'){
                sx=xx;
                sy=yy;
                vis[xx][yy]=1;
            }else{
                sd=(sd+1)%4;
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
