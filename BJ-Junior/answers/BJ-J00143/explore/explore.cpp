#include <bits/stdc++.h>
using namespace std;
int T, n ,m , k,x , y ,d;
char a[1005][1005];
bool pd[1005][1005];
int lu = 0;
int fx[5] = {0,1,0,-1};
int fy[5] = {1,0,-1,0};
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while (T--) {
                memset(pd,0,sizeof(pd));//all 0
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		lu=0;
		for(int i  = 1; i <= n; i ++ ){
			for(int j = 1; j <= m ;j ++ ) {
				cin >> a[i][j];
			}
		}
		pd[x][y] = 1;
		while(k--) {
			x+=fx[d];
			y+=fy[d];
			if(((x >= 1 && x <= n ) && (y >= 1&& y <= m) ) && a[x][y] == '.'){
                //can
                pd[x][y] = 1;
			}else {
                x-=fx[d];
                y-=fy[d];
                d = (d+1)%4;//change
			}

		}
        for(int i =1; i <=n;i ++) {
            for(int j = 1; j <= m ;j ++) {
                if(pd[i][j] == 1) lu ++;//count how many it went
            }
        }
        cout << lu << endl;
	}
	return 0;
}