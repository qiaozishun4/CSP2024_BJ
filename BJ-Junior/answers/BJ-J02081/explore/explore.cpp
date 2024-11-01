/*
	地图探险 ： 模拟

 */

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
char ma[N][N];
int T, n, m, k, x, y, d, cnt, flag[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		cnt = 1; 
		memset(flag, 0, sizeof flag);
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> ma[i][j];
		flag[x][y]++;//标记起点
		for(int i = 1; i <= k; i++){
			int xx = x + dx[d];
			int yy = y + dy[d];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && ma[xx][yy] == '.'){  // 走 一 bu
				x = xx;
				y = yy;
				if(flag[xx][yy] == 0){ //发现新位置
					flag[xx][yy]++;
					cnt++;
				}
			}
			else{
				d = (d+1) % 4; // 切换方向
			}
			
		}
		cout << cnt << endl;
	}
	

	return 0;
}
