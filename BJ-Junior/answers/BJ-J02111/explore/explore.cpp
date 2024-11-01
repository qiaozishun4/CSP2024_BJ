#include <iostream>
#include <cstdio>
using namespace std;
char c[1005][1005];
bool visit[1005][1005];
long long n,m,k;
int bfs(long long x,long long y,long long d){
	if(k > 0){
		k--;
	}else{
		return 0;
	}
	if(d == 0){
		if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && c[x][y + 1] == '.'){
			bfs(x,y + 1,d);
			visit[x][y + 1] = true;
		}else{
			bfs(x,y,(d + 1) % 4);
		}
	}else if(d == 1){
		if(x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m && c[x + 1][y] == '.'){
			bfs(x + 1,y,d);
			visit[x + 1][y] = true;
		}else{
			bfs(x,y,(d + 1) % 4);
		}
	}else if(d == 2){
		if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && c[x][y - 1] == '.'){
			bfs(x,y - 1,d);
			visit[x][y - 1] = true;
		}else{
			bfs(x,y,(d + 1) % 4);
		}
	}else if(d == 3){
		if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m && c[x - 1][y] == '.'){
			bfs(x - 1,y,d);
			visit[x - 1][y] = true;
		}else{
			bfs(x,y,(d + 1) % 4);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin >> T;
	for(long long i = 1;i <= T;i++){
		cin >> n >> m >> k;
		long long x,y,d;
		cin >> x >> y >> d;
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= m;j++){
				cin >> c[i][j];
			}
		}
		visit[x][y] = true;
		bfs(x,y,d);
		long long cnt = 0;
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= m;j++){
				if(visit[i][j] == true){
					cnt++;
					visit[i][j] = false;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
