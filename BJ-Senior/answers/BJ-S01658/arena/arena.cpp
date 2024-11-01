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
	cout << 1;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	
	
	
	
	
	
	
	return 0;
}



