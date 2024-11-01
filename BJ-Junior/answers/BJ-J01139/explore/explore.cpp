#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1000, M = 1000;
char a[N][M];
int flag[N][M];
int main () {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    int iii = 0;
    while (t--) {
		int n, m, k, xx, yy, dd;
		cin >> n >> m >> k >> xx >> yy >> dd;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++){
				flag[i][j] = 0;
			}
		}
		flag[xx-1][yy-1] = 1;
		int x = xx-1, y = yy-1, d = dd;
		//cout << x << " " << y << " " << d << endl;
		for (int i = 0; i < k; i++){
			if (d == 0) {
				if (x < n && y+1 < m && a[x][y+1] != 'x') {
					y+=1;
					flag[x][y] = 1;
				} else {
					d += 1;
					d %= 4;
				}
			} else if (d == 1) {
				if (x+1 < n && y < m && a[x+1][y] != 'x') {
					x+=1;
					flag[x][y] = 1;
				} else {
					d += 1;
					d %= 4;
				}
			} else if (d == 2) {
				if (x < n && y-1 >= 0 && a[x][y-1] != 'x') {
					y-=1;
					flag[x][y] = 1;
				} else {
					d += 1;
					d %= 4;
				}
			} else if (d == 3) {
				if (x-1 >= 0 && y < m && a[x-1][y] != 'x') {
					x-=1;
					flag[x][y] = 1;
				} else {
					d += 1;
					d %= 4;
				}
			}
			//cout << x << " " << y << " " << d << endl;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << flag[i][j] << " ";
				if (flag[i][j] == 1) sum++;
			}
		}
		cout << sum << endl;
		iii++;
	}
	return 0;
} 
