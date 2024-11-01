#include<bits/stdc++.h>


using namespace std;

int T,n,m,k;
int x,y,d,nx,ny;
char jungle[1005][1005];
int jungle_step[1005][1005] = {0};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int ans = 0;

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int c = 1;c <= n;c++) {
            for (int d = 1;d <= m;d++) {
                jungle_step[c][d] = 0;
            }
        }
		jungle_step[x][y] = 1;
		for (int p = 1;p <= n;p++) {
            for (int q = 1;q <= m;q++) {
                cin >> jungle[p][q];
            }
		}
		for (int j = 0;j < k;j++) {
            nx = x + dx[d];
            ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && jungle[nx][ny] == '.') {
                x = nx;
                y = ny;
                jungle_step[x][y]++;
            }
            else {
                d = (d + 1) % 4;
            }
		}
		for (int a = 1;a <= n;a++) {
            for (int b = 1;b <= m;b++) {
                if (jungle_step[a][b] != 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
        ans = 0;
	}
	return 0;
}
