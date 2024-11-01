//(>o^_^o<)
#include <bits/stdc++.h>
using namespace std;
int T;
int n, m, L, V;
int d[100005], v0[100005], a[100005];
int p[100005], lstp;
int wz[1000005];
struct node{double pos; int tp, id; double ed;}nd[200005]; int all, ls, lk;
int nxt[100005];
bool cmp(node a, node b){return a.pos < b.pos;}
int main(){
	freopen("detect5.in", "r", stdin); freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		all = ls = 0;
		for(int i = 1; i <= n; i++){
			cin >> d[i] >> v0[i] >> a[i];
			if(a[i] < 0){	
				double ed = 1.0 * d[i] + (1.0 * V * V - 1.0 * v0[i] * v0[i]) / (2.0 * a[i]);
				node s; s.pos = d[i], s.tp = 1, s.id = i, s.ed = ed;
				nd[++all] = s; ls++; lk++;
			}else{
				if(a[i] == 0){
					if(v0[i] > V){
						node s; s.pos = d[i], s.tp = 1, s.id = i, s.ed = 1000005;
						nd[++all] = s; ls++;
					}else continue;
				}
				double pos = d[i] * 1.0 + (1.0 * V * V - 1.0 * v0[i] * v0[i]) / (2.0 * a[i]);
				node s; s.pos = pos, s.tp = 1, s.id = i, s.ed = 1000005;
				nd[++all] = s; ls++;
			}
		}
		for(int i = 1; i <= m; i++){
			cin >> p[i];
			node s; s.pos = p[i], s.tp = 0, s.id = i, s.ed = 0;
			nd[++all] = s;
		}
		lstp = p[m];
		int ans = 0;
		if(lk == 0){
			for(int i = 1; i <= n; i++){
				if(a[i] < 0) continue;
				if(a[i] == 0 && d[i] <= lstp && v0[i] > V){ans++; continue;}
				if(a[i] == 0) continue;
				double pos = d[i] * 1.0 + (1.0 * V * V - 1.0 * v0[i] * v0[i]) / (2.0 * a[i]);
				if(d[i] > lstp) continue;
				if(pos < 1.0 * lstp) ans++;			
			}
			cout << ans << " " << ((ans == 0) ? m : m - 1) << endl; continue;
		}
		sort(nd + 1, nd + all + 1, cmp); int now = 1000005;
		for(int i = all; i >= 1; i--){
			if(nd[i].tp == 0) now = nd[i].pos;
			else nxt[nd[i].id] = now;
		}
		int cnt = 1;
		for(int i = 1; i <= all; i++){
			if(nd[i].tp == 0) continue;
			if(nd[i].ed <= nxt[nd[i].id] || nxt[nd[i].id] > L || (v0[nd[i].id] <= V && a[nd[i].id] < 0) || (nd[i].pos > lstp && a[nd[i].id] > 0)) continue;
			ans++;
		}
		/*for(int i = 1; i <= all; i++)
			cout << nd[i].id << " " << nd[i].pos << " " << nd[i].ed << endl;*/
		for(int i = 1; i <= all; i++){
			if(nd[i].tp == 0) continue;
			if(nd[i].ed <= nxt[nd[i].id] || nxt[nd[i].id] > L || v0[nd[i].id] <= V) continue;
			//if(nd[i].ed >= lstp) continue;
			double mi = nd[i].ed;
			while(i <= all){
				i++;
				if(nd[i].tp == 0) continue;
				if(nd[i].ed <= nxt[nd[i].id] || nxt[nd[i].id] > L || v0[nd[i].id] <= V) continue;
				if(mi >= nxt[nd[i].id]) mi = min(mi, nd[i].ed);
				else break;
			}
			//if(i >= all && nd[i].tp != 0) cnt--;
			//cout << i << endl;
			cnt++; i--;
		}
		cout << ans << " " << ((ls == n) ? m - cnt + 1 : m - cnt) << endl;
	}
	return 0;
}
//芙芙可爱捏(>o^_^o<)