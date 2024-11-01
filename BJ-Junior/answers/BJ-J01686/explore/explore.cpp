#include<iostream>
#include<cstdio>
using namespace std;
const long long N = 1e3 + 5;
char a[N][N], vis[N][N];
long long T;
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T --){
		long long n, m, k, x, y, d;
		cin >> n >> m >> k >> x >> y >> d;
		//cout << n << ' ' << m << ' ' << k << ' '<< x << ' ' << y << ' ' << d << '\n';
 		for(long long i = 1; i <= n; i ++){
			for(long long j = 1; j <= m; j ++){
				cin >> a[i][j];
				vis[i][j] = 0;
			}
		}
		long long ans = 1;
		vis[x][y] = 1;
		for(long long i = 1; i <= k; i ++){
			long long nx = x, ny = y;
			if(d == 0){
				ny ++;
			}
			else if(d == 1){
				nx ++;
			}
			else if(d == 2){
				ny --;
			}
			else if(d == 3){
				nx --;
			}
			
			if(a[nx][ny] == 'x' || nx > n || nx < 1 || ny > m || ny < 1){
				d = (d+1) % 4;
				continue;
			}
			x = nx;
			y = ny;
			if(vis[x][y]) continue;
			ans ++;
			vis[x][y] = 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
