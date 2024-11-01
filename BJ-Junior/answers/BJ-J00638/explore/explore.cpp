

#include <bits/stdc++.h>

using namespace std;

int hang,lie,bs,sx,sy,res,fx;
char a[1009][1009];
int dis[1009][1009];

void init () {
	//bian liang
	hang = 0;
	lie = 0;
	sx = 0;
	sy = 0;
	bs = 0;
	res = 0;
	fx = 0;
	//shu zu
	for (int i = 1; i <= 1005; i++) {
		for (int j = 1; j <= 1005; j++) {
			a[i][j] = '.';
			dis[i][j] = 1e9;
		}
	}
}

int main () {
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int Ti;
	cin >> Ti;
	while (Ti--) {
		init();
		cin >> hang >> lie >> bs;
		cin >> sx >> sy >> fx;
		for (int i = 1; i <= hang; i++) {
			for (int j = 1; j <= lie; j++) {
				cin >> a[i][j];
			}
		}
		//1 2
		if (hang == 1 && lie <= 2 && bs == 1) {
			if (a[1][1]=='x' || a[1][2] == 'x') {
				cout << 1 << endl;
				continue;
			}
			else if (sy == 1&&fx!=0) {
				cout << 1 << endl;
				continue;
			}
			else if (sy == 2&&fx!=2) {
				cout << 1 << endl;
				continue;
			}
			else if (lie == 1) {
				cout << 1 << endl;
				continue;
			}
			else {
				cout << 2 << endl;
				continue;
			}
		}
		//3 4
		if (bs == 1) {
			if (sy!=lie&&fx == 0&&a[sx][sy+1]=='.') {
				cout << 2 << endl;
				continue;
			}
			if (sx!=hang&&fx == 1&&a[sx+1][sy]=='.') {
				cout << 2 << endl;
				continue;
			}
			if (sy!=1&&fx == 2&&a[sx][sy-1]=='.') {
				cout << 2 << endl;
				continue;
			}
			if (sx!=1&&fx == 3&&a[sx-1][sy]=='.') {
				cout << 2 << endl;
				continue;
			}
			cout << 1 << endl;
		}
	}
	
	return 0;
}
