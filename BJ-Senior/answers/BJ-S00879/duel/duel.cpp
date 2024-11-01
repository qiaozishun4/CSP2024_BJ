#include <bits/stdc++.h>
#define int long long
using namespace std;


int n,vis[100010],a[100010],res;
vector<int> vec;
set<int> st;
map<int,int> mp;



signed main(){


	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin >> n;
	res = n;

	
	for(int i = 1; i <= n; i++){
		int xx = 0;
		cin >> xx;
		if(st.find(xx) != st.end()) mp[xx]++;
		else {
			st.insert(xx);
			vec.push_back(xx);
			mp[xx]++;
		}
		
	}
	int size = vec.size();
	
	sort(vec.begin(),vec.end());
	
	
	for(int i = 0; i < size-1; i++){
		res -= min(mp[vec[i+1]],mp[vec[i]]);
		
		
	}
	cout << res<< endl;

	return 0;
}
