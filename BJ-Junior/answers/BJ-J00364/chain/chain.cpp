#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 100009, M = 109, mod = 1e9 + 7, inf = 1e9;

vector<int> ve[N];
bool vis[M][N << 1];
int gt[N << 1];

void solved() {
	// int n, k, m;	cin >> n >> k >> m;
	int n, k, m;	scanf("%d%d%d", &n, &k, &m);
	_for(i, 1, n) {
		// int x;	cin >> x;
		int x;	scanf("%d", &x);
		ve[i].resize(x + 1);
		ve[i][0] = x;
		// _for(j, 1, x) cin >> ve[i][j];
		_for(j, 1, x) scanf("%d", &ve[i][j]);
	}
	gt[1] = -1;
	_for(t, 1, 100) {
		// 标记哪些位置可作为开头
		_for(i, 1, n) {
			_for(j, 1, ve[i][0]) {
				int x = ve[i][j];
				if(gt[x] == 0 || gt[x] == i) continue;
				ve[i][j] = -x;
			}
		}
		// 迭代哪些位置可以进行下一轮扩散
		_for(i, 1, 2e5 + 1) gt[i] = 0;
		_for(i, 1, n) {
			int pre = -inf;
			_for(j, 1, ve[i][0]) {
				int x = ve[i][j], fp = pre;
				if(x < 0) {
					x = -x;
					pre = j;
				}
				if(j - fp < k) {
					if(gt[x] == 0) gt[x] = i;
					else if(gt[x] != i) gt[x] = -1;
					vis[t][x] = true;
				}
				ve[i][j] = x;
			}
		}
	}
	while(m --) {
		// int r, c;	cin >> r >> c;
		// if(vis[r][c]) cout << 1 << endl;
		// else cout << 0 << endl;
		int r, c;	scanf("%d%d", &r, &c);
		if(vis[r][c]) printf("1\n");
		else printf("0\n");
	}
	_for(i, 1, n) ve[i].clear();
	_for(i, 1, 100) _for(j, 1, 2e5 + 1) vis[i][j] = false;
	_for(i, 1, 2e5 + 1) gt[i] = 0;
	return ;
}
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0), cout.tie(0);
	// int ttx;	cin >> ttx;	while(ttx --)
	int ttx;	scanf("%d", &ttx);	while(ttx --)
	solved();
	return 0;
}
