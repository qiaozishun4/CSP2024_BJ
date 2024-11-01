#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int MAXN = 1e5+5;
const ull MOD = 10007;

int T, n, k, q, val, r, c, cnt;
int l[MAXN];
vector <int> num[MAXN];

ull QuickPow(ull val, int k){
	ull res = 1;
	while (k){
		if (k&1) res = res*val;
		val = val*val;
		k >>= 1;
	}
	return res;
}

struct Edge{
	int to; 
	int id;
};
vector <Edge> G[MAXN];
bool f;

map <ull, bool> vis;

void dfs(int step, int val, int fa){
	if (step == 0 && val == 1){
		f = true;
		return;
	}
	for (int i=0; i<G[val].size(); i++){
		if (G[val][i].id == fa) continue;
		dfs(step-1, G[val][i].to, G[val][i].id);
	}
}

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &k, &q);
		for (int i=1; i<=n; i++){
			scanf("%d", &l[i]);
			for (int j=1; j<=l[i]; j++){
				scanf("%d", &val);
				num[i].push_back(val);
	
			}
		}		
		for (int i=1; i<=n; i++){
			for (int j=1; j<=l[i]; j++){
				ull tmp = 0;
				for (int pos=max(0, j-1-k+1); pos<j-1; pos++){
					tmp = tmp + (ull)(num[i][pos])*QuickPow(MOD, (j-1)-pos);
					if (vis[tmp] == true) continue;
					vis[tmp] = true; cnt++; G[num[i][j-1]].push_back({num[i][pos], cnt});
				}
			}
		}
		for (int i=1; i<=q; i++){
			scanf("%d%d", &r, &c);
			f = false;
			dfs(r, c, 0);
			if (f == true) printf("1\n");
			else printf("0\n");
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
1
3 3 7
5 1 2 3 4 1
3 1 2 5
3 5 1 6
*/


