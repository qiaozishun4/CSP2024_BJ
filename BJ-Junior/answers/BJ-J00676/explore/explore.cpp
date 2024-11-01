#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
bool f[1005][1005][8][2];
int n,m;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int explore(int x,int y,int z,int k,int d){
    int X=x,Y=y;
    int cnt=0;
    while(k!=0){
        k--;
        int nx=x+dx[d],ny=y+dy[d];
        if(min(nx,ny)<1||nx>n||ny>m||f[nx][ny][z][1]==0){
            d++;
            if(d==4) d=0;
            continue;
        }
        f[nx][ny][z][0]=true;
        x=nx,y=ny;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(f[i][j][z][0]||i==X&&j==Y) cnt++;
    return cnt;
}
int main(){
    freopen("explore5.in","r",stdin);
    freopen("explore5.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int w=1;w<=n;w++) for(int j=1;j<=m;j++){
            char g;
            cin>>g;
            if(g=='x') continue;
            if(g=='.') f[w][j][i][1]=1;
        }
        cout<<explore(x,y,i,k,d)<<"\n";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

