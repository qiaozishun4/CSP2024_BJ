#include<iostream>
#include<cstring>
using namespace std;
const int N=1010, movement[4][2]={{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};
int T, n, m, k, ans;
char _map[N][N];
bool mark[N][N];
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
        memset(mark, 0, sizeof mark);
        ans=1;
        int sx, sy, sd;
        scanf("%d%d%d%d%d%d", &n, &m, &k, &sx, &sy, &sd);
        mark[sx][sy]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>_map[i][j];
            }
        }
        int x=sx, y=sy, d=sd;
        while(k--){
            int lastx=x, lasty=y;
            x+=movement[d][0];
            y+=movement[d][1];
            if(x>=1&&x<=n&&y>=1&&y<=m&&_map[x][y]=='.'&&!mark[x][y]){
                ans++;
                mark[x][y]=1;
            }else{
                d=(d+1)%4;
                x=lastx;
                y=lasty;
            }
        }
        printf("%d\n", ans);
	}
	return 0;
}
