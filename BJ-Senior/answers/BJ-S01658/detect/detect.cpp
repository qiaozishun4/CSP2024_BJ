#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
int n;
set<int> s;
map<int,int> mp;
int ans,ans1;
int maxp,maxd,mind = 1e6;
bool flag;
int d[N],v[N],p[N],a[N];
struct node{
	int d,v,a,f;
}c[N];
bitset<20> bs;
vector<node> g;
bool cmp(node a,node b){
	return a.d < b.d;
}
void solve(){
	int l,V,m;
	memset(c, 0, sizeof c);
	cin >> n >> m >> l >> V;
	for(int i =1;i <= n;i ++){
		cin >> c[i].d >> c[i].v >> c[i].a;
		if(c[i].v > V) c[i].f = 1;
		maxd = max(maxd,c[i].d);
		mind = min(mind, c[i].d);
	}
	for(int i = 1;i <= m;i ++){
		cin >> p[i];
		maxp = max(maxp, p[i]);
	}
	for(int i = 1;i <= n;i ++) {
		if(c[i].f == 1){
			if(maxp >= d[i]) ans++;
		}
	}
	if(maxp >= maxd){
		ans1 = m - 1;
	}
	if(maxp < mind){
		ans1  = m;
	}
	cout << ans << ' ' << ans1 << '\n';
	ans = 0;
	maxp = maxd = 0;
	mind = 1e6;
}
void fre(){
	freopen("detect.in","r",stdin);
	freopen("detect.out", "w",stdout);
}
int main(){
	fre();
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	
	
	
	
	
	
	
	return 0;
}



