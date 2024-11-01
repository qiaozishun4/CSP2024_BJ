# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool flag[1 << 20];
int k, res, tk, a[N], b[N], c[N], x[10], win[20][1 << 20];
char d[20][1 << 20];

int Do_Game(){
	for (int i = 1; i <= tk; i++) win[i][0] = 0;
	win[1][0] = (1 << tk);
	for (int i = 1; i <= (1 << tk); i++) win[1][i] = i;
	for (int i = 2; i <= tk; i++){
		for (int j = 1; j <= win[i - 1][0]; j += 2){
			if (d[i][(j >> 1) + 1] == '1'){
				if (b[win[i - 1][j + 1]] >= i - 1) win[i][++win[i][0]] = win[i - 1][j + 1];
				else win[i][++win[i][0]] = win[i - 1][j];
			}
			else {
				if (b[win[i - 1][j]] >= i - 1) win[i][++win[i][0]] = win[i - 1][j];
				else win[i][++win[i][0]] = win[i - 1][j + 1];
			}
		}
	}
	return win[tk][1];
}

void DFS(int now){
	if (now > (1 << tk)){
		int winner = Do_Game();
		if (!flag[winner]) res += winner;
		flag[winner] = 1;
		return;
	}
	for (int i = 0; i <= tk + 1; i++){
		b[now] = i;
		DFS(now + 1);
	}
}

int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	k = log(n) / log(2) + (n & 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> c[i];
	for (int i = 1; i <= k; i++) cin >> (d[i] + 1);
	int t;
	cin >> t;
	while (t--){
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i = 1; i <= n; i++) b[i] = a[i] ^ x[i % 4];
		int ans = 0;
		for (int i = 1; i <= m; i++){
			memset(flag, 0, sizeof(flag));
			tk = log(c[i]) / log(2) + (n & 1);
			res = 0;
			DFS(c[i] + 1);
			ans ^= (i * res); 
		}
		cout << ans << endl;
	}
	return 0;
}