#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 10;
int n;
int r[N];
map<int,int> mp;
int ans;
bool flag;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> r[i];
		mp[r[i]] ++;
		if(mp[r[i]] > 1) flag = 1;
 	}
	for(int i = 1;i <= n;i ++){
		ans = max(ans,mp[r[i]]);
	}
	
	cout << ans;
	
	return 0;
}



