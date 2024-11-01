#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lc x << 1
#define rc x << 1 | 1
const int MX = 1e5 + 7;
ll sum[MX << 2],tag[MX << 2];
int L[MX << 2],R[MX << 2];
void upd(int x){sum[x] = sum[lc] + sum[rc];}
void pushdown(int x){
	if(tag[x]){
		sum[lc] = sum[rc] = 0;
		tag[lc] = tag[rc] = 1;
		tag[x] = 0;
	}
}
void build(int x,int l,int r){
	if(l == r){sum[l] = l;return;}
	int mid = l + r >> 1;
	build(lc,l,mid);build(rc,mid + 1,r);
	upd(x);
}
void modify(int x,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr){sum[x] = 0;tag[x] = 1;return;}
	int mid = l + r >> 1;pushdown(x);
	if(ql <= mid)modify(lc,l,mid,ql,qr);
	else modify(rc,mid + 1,r,ql,qr);
	upd(x);
}
ll query(int x,int l,int r,int ql,int qr){
	if(ql <= l && r <= qr)return sum[x];
	int mid = l + r >> 1;ll ret = 0;pushdown(x);
	if(ql <= mid)ret += query(lc,l,mid,ql,qr);
	else ret += query(rc,mid + 1,r,ql,qr);
	upd(x);
}
int type[MX];
int def[MX << 1];
int a[MX],A[MX],c[MX],id[MX];
int log2(int x){return 31 - __builtin_clz(x);}
string S,T = "";
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios :: sync_with_stdio(false);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= m;i++)cin >> c[i];
	for(int i = 1;i <= m;i++)id[i] = i;
	sort(id + 1,id + 1 + m,[&](int x,int y){return c[x] < c[y];});
	int k = ((1 << log2(n)) == n ? log2(n) : log2(n) + 1);
	for(int i = 1;i <= k;i++){
		cin >> S;
		T += S;
	}
	for(int i = T.size() - 1;i >= 0;i--)type[i] = T[i] - '0';
	int T;cin >> T;
	while(T--){
		int X[4];cin >> X[0] >> X[1] >> X[2] >> X[3];
		for(int i = 1;i <= n;i++)A[i] = a[i] ^ X[i % 4];
		int cur = 1;num = 1 << k;
		build(1,1,num);
		cout << 0 << '\n';
	}
	return 0;
}