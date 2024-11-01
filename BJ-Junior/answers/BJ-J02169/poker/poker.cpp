#include <bits/stdc++.h>

using namespace std;

map<string, bool> mp;
int n;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		mp[s] = true;
	}
	cout << 52 - mp.size() << '\n';
	return 0;
}