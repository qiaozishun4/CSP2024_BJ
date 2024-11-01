#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 10;
int n,m,k;
int x,y;
vector<int> g;
int d[] = {6,2,5,5,4,5,6,3,7,6};
pair<int,int> a[N];
void solve(){
	cin >> n;
	g.clear();
	if(n < 2){
		cout << -1;
		return;
	}
	for(int i = 0; i<= 9;i ++){
		a[i].fi = d[i];
		a[i].se = i;
	}
	sort(a , a + 9);
	int i = 0;
	while(n){
		i ++;
		if(n > a[i].se){
			g.pb(a[i].fi);
			n -= a[i].se;
		}
		
	}
	for(auto i : g){
		cout << i;
	}
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}






	
	return 0;
}
