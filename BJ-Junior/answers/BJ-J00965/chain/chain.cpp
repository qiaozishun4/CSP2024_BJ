#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
int n, k, q;
int L[N], vis[N << 1];

struct Qus{
	int r, c, id;
}qu[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("chain.in", "r", stdin); freopen("chain.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; ++i){
			cin >> L[i];
			for(int j = 1; j <= L[i]; ++j){
				int tmp;
				cin >> tmp;
				vis[tmp] = 1;
			}
		}
		for(int i = 1; i <= q; ++i){
			cin >> qu[i].r >> qu[i].c;
			if(vis[qu[i].c]) cout << "1" << endl;
			else cout << "0" << endl;
		}
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}