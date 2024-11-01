#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e3+5;
bool F;
bool b[N][N],v[N][N];
int n,m,k,x,y,d,X,Y,cnt = 0,T;
char c;
int main() {
	F = freopen("explore.in","r",stdin);
	F = freopen("explore.out","w",stdout);
	cin >> T;
	while (T--) {
		memset(v,0,sizeof(v));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		v[x][y] = 1;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				cin >> c;
				if (c == 'x') {
					b[i][j] = 1;
				} else {
					b[i][j] = 0;
				}
			}
		}
		cnt = 1;
		//cout << x << ' ' << y << ' ' << d << ' ' << cnt << endl;
		while (k--) {
			X = x;
			Y = y;
			switch (d) {
				case 0:Y++;break;
				case 1:X++;break;
				case 2:Y--;break;
				case 3:X--;break;
			}
			if (1 <= X && X <= n && 1 <= Y && Y <= m && !b[X][Y]) {
				x = X;
				y = Y;
				if (!v[x][y]) {
					v[x][y] = 1;
					cnt++;
				}
			} else {
				//cout << X << ' ' << Y << ' ' << b[X][Y] << endl;
				d = (d + 1) % 4;
			}
			//cout << x << ' ' << y << ' ' << d << ' ' << cnt << endl;
		}/*
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				cout << b[i][j] << ' ';
			}
			cout << endl;
		}*/
		cout << cnt << endl;
	}
	return 0;
}
