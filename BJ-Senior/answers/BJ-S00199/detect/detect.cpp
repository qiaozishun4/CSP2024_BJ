#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5, MAXM = 1e5+5, MAXL = 4e5+5;

int T, n, m, tot, l, r, res, ans1, ans2;
double liml[MAXN], limr[MAXN];
double L, V;
double p[MAXM];
bool nok[MAXN];
bool delline[MAXM];

struct Line{
	double l, r;
}line[MAXN];

struct Car{
	double pos, limpos, v, a;
}car[MAXN];

double getv(int carid, int pid){
	double v = car[carid].v, a = car[carid].a, deltas = p[pid]-car[carid].pos;
	return sqrt(v*v+2*a*deltas);	
}

bool cmp(Line a, Line b){
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;	
}

pair<int, int> segtree[MAXL];
int lazytag[MAXL];

void build(int l, int r, int root){
	segtree[root].first = 0;
	segtree[root].second = l;
	lazytag[root] = 0;
	if (l == r){
		segtree[root].first = 0;
		segtree[root].second = l;
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, root*2);
	build(mid+1, r, root*2+1);
	if (segtree[root*2].first >= segtree[root*2+1].first) segtree[root] = segtree[root*2];
	else segtree[root] = segtree[root*2+1];
}

void maintain(int l, int r, int root){
	int mid = (l+r)/2;
	if (l != r && lazytag[root]){
		segtree[root*2].first += lazytag[root];
		segtree[root*2+1].first += lazytag[root];
		lazytag[root*2] += lazytag[root];
		lazytag[root*2+1] += lazytag[root];
		lazytag[root] = 0;
	}
}

void update(int getl, int getr, int c, int l, int r, int root){
	if (getl <= l && getr >= r){
		segtree[root].first += c;
		lazytag[root] += c;
		return;
	}
	maintain(l, r, root);
	int mid = (l+r)/2;
	if (getl <= mid){
		update(getl, getr, c, l, mid, root*2);	
	}
	if (getr > mid){
		update(getl, getr, c, mid+1, r, root*2+1);
	}
	if (segtree[root*2].first >= segtree[root*2+1].first) segtree[root] = segtree[root*2];
	else segtree[root] = segtree[root*2+1];
}

pair<int, int> get(int getl, int getr, int l, int r, int root){
	if (getl <= l && getr >= r){
		return segtree[root];
	}
	maintain(l, r, root);
	int mid = (l+r)/2;
	pair<int, int> res, tmp; 
	if (getl <= mid){
		res = get(getl, getr, l, mid, root*2);	
	}
	if (getr > mid){
		tmp = get(getl, getr, mid+1, r, root*2+1);
		if (tmp.first > res.first) res = tmp;
	}
	return res;
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		scanf("%lf%lf", &L, &V);
		for (int i=1; i<=n; i++){
			nok[i] = false; liml[i] = 0; limr[i] = 0;
			scanf("%lf%lf%lf", &car[i].pos, &car[i].v, &car[i].a);	
			if (car[i].a >= 0) car[i].limpos = car[i].pos+L;
			else car[i].limpos = car[i].pos-car[i].v*car[i].v/(2*car[i].a);
		}
		for (int i=1; i<=m; i++){
			scanf("%lf", &p[i]);
		}
		ans1 = 0;
		for (int i=1; i<=n; i++){
			if (car[i].a >= 0){
				if (p[m] < car[i].pos) continue;
				if (getv(i, m) > V) nok[i] = true, limr[i] = m, ans1++;
			}	
			else{
				if (p[m] < car[i].pos) continue;
				int pos = lower_bound(p+1, p+m+1, car[i].pos)-p;
				if (p[pos] > car[i].limpos) continue;
				if (getv(i, pos) > V) nok[i] = true, liml[i] = pos, ans1++;
			}	
		}
		printf("%d ", ans1); tot = 0;
		for (int i=1; i<=n; i++){
			if (nok[i] == false) continue;
			if (car[i].a >= 0){
				l = 1; r = limr[i]; res = 0;
				while (l <= r){
					int mid = (l+r)/2;
					// cout << l << " " << mid << " " << r << endl;
					if (p[mid] < car[i].pos){
						l = mid+1; continue;
					}
					if (getv(i, mid) > V) res = mid, r = mid-1;
					else l = mid+1;
				}
				liml[i] = res;
			}	
			else{
				l = liml[i]; r = m; res = 0;
				while (l <= r){
					int mid = (l+r)/2;
					if (p[mid] > car[i].limpos){
						r = mid-1; continue;
					}	
					if (getv(i, mid) > V) res = mid, l = mid+1;
					else r = mid-1;
				}
				limr[i] = res;
			}
			tot++;
			line[tot].l = liml[i];
			line[tot].r = limr[i];
			// cout << i << " " << liml[i] << " " << limr[i] << endl;
		}
		// sort(line+1, line+tot+1, cmp);
		if (tot == 0){
			printf("%d\n", m);
			continue;
		}
		build(1, m, 1);
		for (int i=1; i<=tot; i++){
			delline[i] = false;
			update(line[i].l, line[i].r, 1, 1, m, 1);	
		}
		ans2 = 0;
		while (true){
			pair<int, int> res = get(1, m, 1, m, 1);
			//cout << "sum: ";
			//for (int i=1; i<=m; i++) cout << get(i, i, 1, m, 1).first << " ";
			//cout << endl;
			//cout << "oper: " << res.first << " " << res.second << endl;
			if (res.first <= 0) break;
			int pos = res.second; ans2++;
			for (int i=1; i<=tot; i++){
				if (delline[i] == false && pos >= line[i].l && pos <= line[i].r){
					delline[i] = true; update(line[i].l, line[i].r, -1, 1, m, 1);
				}
			}	
		}
		printf("%d\n", m-ans2);
	}
	return 0;
}

