#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
bool Map[1100][1100],vis[1100][1100];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char c;
int tx,ty;
bool ch(int x,int y){
    return (x>0&&y>0&&x<=n&&y<=m&&Map[x][y]);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> c;
                vis[i][j]=0;
                Map[i][j] = c=='.';
            }
        }
        int cnt=1;
        vis[x][y]=1;
        while(k--){
            if(ch(x+dx[d],y+dy[d])){
                x+=dx[d];y+=dy[d];
                if(vis[x][y]==0){
                    vis[x][y]=1;
                    cnt++;
                }
            }
            else d=(d+1)%4;
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
