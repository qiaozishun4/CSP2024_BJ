#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char mp[1024][1024];
bool go[1024][1024];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        memset(go,false,sizeof go);
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        x--,y--;
        for (int j=0;j<n;j++)
            scanf("%s",mp[j]);
        int ans=1;
        go[x][y]=true;
        for (int j=1;j<=k;j++){
            for (int k=0;k<4;k++){
                int nx=x+dx[d];
                int ny=y+dy[d];
                if (nx<0||ny<0||nx>=n||ny>=m){
                    d=(d+1)%4;
                    break;
                }
                if (mp[nx][ny]=='x'){
                    d=(d+1)%4;
                    break;
                }
                if (!go[nx][ny])
                    ans++;
                go[nx][ny]=true;
                x=nx;
                y=ny;
                break;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
