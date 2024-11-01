#include<bits/stdc++.h>
using namespace std;

map<string, bool> mp;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		mp[s] = true;
	}
	
	int sz = mp.size();
	printf("%d\n", max(0, 52 - sz));
	return 0;
}