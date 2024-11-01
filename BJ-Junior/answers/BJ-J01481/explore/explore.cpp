#include <bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
char cc[1005];
int mapp[1005][1005];
bool vis[1005][1005];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int step,cnt;

bool border(){
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    if(nx < 0||nx >= n || ny < 0||ny >= m){
        return 0;
    }
    if(mapp[nx][ny] == 0){
        return 0;
    }
    return 1;
}
int main(){
    freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i = 0;i<n;i++){
            scanf("%s",&cc);
            for(int j = 0;j<m;j++){
                if(cc[j] == '.'){
                    mapp[i][j] = 1;
                }else{
                    mapp[i][j] = 0;
                }
                vis[i][j] = 0;
            }
        }
        step = 0,cnt = 1;
        x--,y--;
        vis[x][y] = 1;
        while(step<k){
            if(!border()){
                d = (d+1)%4;
                step++;
                continue;
            }
            x += dir[d][0];
            y += dir[d][1];
            if(!vis[x][y]){
                vis[x][y] = 1;
                cnt++;
            }
            step++;
        }
        cout<<cnt<<endl;
	}
	return 0;
}
