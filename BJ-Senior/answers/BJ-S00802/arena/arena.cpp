#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
const int P = 350;
int n, m, K, a[N], b[N];
bool d[P][N];
char dt[P][N];
int fa[N];
ll ans;

struct Qus{
	int num, id;
	bool operator<(const Qus & qu)const{
		return num < qu.num;
	}
}c[N];

int Lag(int x){
	for(int i = 20; i >= 1; --i){
		if((1 << i) >= x && (1 << (i - 1)) < x) return i;
	}
	return 0;
}

bool checkA(int x){
	for(int i = 20; i >= 0; --i){
		if((1 << i) < x) return false;
		if((1 << i) == x) return true;
	}
}

int Find(int L, int R){
	int now = R - L + 1;
	for(int i = L; i <= R; ++i) b[i] = i;
	for(int i = 1; i <= Lag(R - L + 1); ++i){
		for(int j = 0; j < now; j += 2){
			int lst = b[L + j], tmp = b[L + j + 1], tmp2;
			if(d[i][((L-1) >> i) + j / 2 + 1] == 0) tmp2 = lst;
			else tmp2 = tmp;
			if(a[tmp2] >= i) lst = tmp2;
			else lst = lst + tmp - tmp2;
			b[L + j / 2] = lst;
		}
		now /= 2;
	}
	return b[L];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("arena.in", "r", stdin); freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> fa[i];
	for(int i = 1; i <= m; ++i) cin >> c[i].num, c[i].id = i;
	sort(c + 1, c + m + 1);
	int opA = 1;
	for(int i = 1; i <= m; ++i) if(!checkA(c[i].num)) opA = 0;
	K = Lag(n);
	for(int i = 1; i <= K; ++i){
		for(int j = 1; j <= (1 << (K - i)); ++j){
			cin >> dt[i][j];
			if(dt[i][j] == '1') d[i][j] = 1;
		}
	}
	int T;
	cin >> T;
	while(T--){
		int X[6];
		for(int i = 0; i < 4; ++i) cin >> X[i];
		for(int i = 1; i <= n; ++i) a[i] = fa[i] ^ X[i % 4];
		if(opA){
			ans = 0;
			int lst = 1, now = 0;
			for(int i = 1; i <= Lag(c[m].num) + 1; ++i){
				while(now < m && c[now + 1].num == (1 << (i - 1))){
					now++;
					ans ^= 1ll * c[now].id * lst;
				}
				if(now == m) break;
				int tmp = Find((1 << (i - 1)) + 1, 1 << i), tmp2;
				//cout << lst << " " << tmp << endl;
				if(d[i][1] == 0) tmp2 = lst;
				else tmp2 = tmp;
				if(a[tmp2] >= i) lst = tmp2;
				else lst = lst + tmp - tmp2;
				//cout << ans << endl;
			}
			cout << ans << endl;
		}
	}
	return 0;
}