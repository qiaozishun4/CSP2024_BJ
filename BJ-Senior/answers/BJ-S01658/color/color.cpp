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
bool vis[N];
int ans;
bool flag;
int b[N];
struct node{
	int v,p,f,fl;
}a[N];
vector<node> g;
bool cmp(node a,node b){
	if(a.v != b.v)return a.v > b.v;
	else return a.p < b.p;
	
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i].v;
		b[i] = a[i].v;
		a[i].p = i;
		mp[a[i].v] ++;
	}
	for(int i = 1;i <= n;i ++){
		if(mp[a[i].v] > 1) s.insert(a[i].v);
	}
	//sort(g.begin(),g.end(),cmp);
	//for(int i = 0 ;i < g.size();i += 2){
	//	vis[g[i].v] = vis[g[i + 1].v] = 1;
	//	g[i].f = 0, g[i + 1].f = 0;
	//	for(int j = g[i].p + 1; j < g[i + 1].p;j ++){
	//		if(!vis[g[i].v]){
	//			g[i].f = 1;
	//			vis[g[i].v] = 1;
	//		}
		//cout << g[i].v << ' ';
	//	}
		//ans += g[i].v;
		
	//}
	for(auto i : s){
		ans += i;
	}
	if(s.empty()) cout << 0 << '\n';
	else cout << ans << '\n';
	ans = 0;
	mp.clear();
	s.clear();
	g.clear();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	
	
	
	
	
	
	
	return 0;
}



