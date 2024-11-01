#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int m = 0;
double l = 0;
double V = 0;
struct qwq{
	int d;
	int v;
	int a;
}lst[200010];
int ct = 0;
struct zsh{
	int l;
	int r;
}op[200010];
int read(){
	int x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int p[200010];
int tt[1000010];
int t2[1000010];
bool cmp(zsh a, zsh b){
	if(a.r == b.r) return a.l < b.l;
	return a.r < b.r;
}
struct tree_node{
	int mn = 2147483647;
}t[400010];
void change(int x, int l, int r, int ps, int k){
	if(l == r){
		t[x].mn = k;
		return;
	}
	int mid = (l + r) >> 1;
	if(ps <= mid){
		change(x << 1, l, mid, ps, k);
	}
	else{
		change(x << 1 | 1, mid + 1, r, ps, k);
	}
	t[x].mn = min(t[x << 1].mn, t[x << 1 | 1].mn);
}
int query(int x, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return t[x].mn;
	}
	int mid = (l + r)  >> 1;
	int ans = 2147483647;
	if(ql <= mid){
		ans = min(ans, query(x << 1, l, mid, ql, qr));
	}
	if(qr > mid){
		ans = min(ans, query(x << 1 | 1, mid + 1, r, ql, qr));
	}
	return ans;
}
signed main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "r", stdin);
	int T = read();
	while(T --){
	ct = 0;
	n = read();
	m = read();
	l = read();
	V = read();
	l ++;
	for(int i = 0; i <= l; i++){
		tt[i] = 0;
		t2[i] = 0;
	}
//	cout << '\n';
	for(int i = 1; i <= n; i++){
		lst[i].d = read() + 1;
		lst[i].v = read();
		lst[i].a = read();
		if(lst[i].a == 0){
			if(lst[i].v > V){
				op[++ ct].l = lst[i].d;
				op[ct].r = l;
//				cout << i << " op1\n";
			}
		}
		if(lst[i].a > 0){
			if(lst[i].v > V){
				op[++ ct].l = lst[i].d;
				op[ct].r = l;
//				cout << i << " op2\n";
			}
			else{
				double cur = (V * V - double(lst[i].v * lst[i].v)) / (2.0 * lst[i].a);
				if((int)(V * V - (lst[i].v * lst[i].v)) % (2 * lst[i].a) == 0){
					cur ++;
				}
				else{
					cur = (int)cur + 1;
				}
				if(cur + lst[i].d <= l){
					op[++ ct].l = cur + lst[i].d;
					op[ct].r = l;
//					cout << i << " op3\n";
				}
			}
		}
		if(lst[i].a < 0){
			if(lst[i].v > V){
				double cur = (V * V - double(lst[i].v * lst[i].v)) / (2.0 * lst[i].a);
				if((int)(V * V - (lst[i].v * lst[i].v)) % (2 * lst[i].a) == 0){
					cur --;
				}
				else{
					cur = (int)cur;
				}
				op[++ ct].l = lst[i].d;
				op[ct].r = min(cur + lst[i].d, l);
//				cout << i << " op4\n";
			}
		}
	}
	int mxp = 0;
	for(int i = 1; i <= m; i++){
		p[i] = read() + 1;
		tt[p[i]] = 1;
		mxp = max(mxp, p[i]);
	}
	for(int i = 1; i <= l; i ++){
		tt[i] += tt[i - 1];
	}
	int ans1 = 0;
	int mxl = 0;
	int ty = 0;
	int uyu = 0;
	for(int i = 1; i <= ct; i++){
//	cout << op[i].r << " " << op[i].l << endl;
		if(tt[op[i].r] - tt[op[i].l - 1] > 0){
			ans1 ++;
			mxl = max(mxl, op[i].l);
		}
		else{
			op[i].r = 2147483647;
			op[i].l = 2147483647;
			uyu ++;
		}
		
	}
	sort(op + 1, op + 1 + ct, cmp);
	for(int i = 1; i <= ct; i++){
		if(op[i].l != 2147483647){
			t2[op[i].l - 1] ++;
			t2[op[i].r] --;
		}
	}
	for(int i = 1; i <= l; i++){
		t2[i] += t2[i - 1];
	}
	int mx = 0;
	int xd = 0;
	int lp = 0;
	change(1, 1, l + 1, 1, 0);
	int ans2 = 2147483647;
	for(int i = 1; i <= m; i++){
		if(t2[p[i]] == 0){ty++;}
		while(op[xd].r < p[i] && xd <= ct){
			mx = max(mx, op[xd++].l);
		}
		while(p[lp] < mx){
			lp ++;
		}
//		cout << lp << " " << i << endl;
	int cur = query(1, 1, l + 1, lp + 1, i) + 1;
//		cout << cur << "  ";
		if(p[i] >= mxl){
			ans2 = min(ans2, cur);
		}
		change(1, 1, l + 1, i + 1, cur);
	}
	change(1, 1, l + 1, 1, 2147483647);
	for(int i = 1;i <= m; i++){
		change(1, 1, l + 1, i + 1, 2147483647);
	}
	cout << ans1 << " " << m - ans2 << '\n'; 
	}
	return 0;
}