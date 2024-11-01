#include <bits/stdc++.h>
using namespace std;

map<string, bool> m;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, ans=52;
	string c;
	cin >> n;
	for(int i=1;i <= n;i++){
		cin >> c;
		if(m.count(c)) continue;
		else{
			m[c]=1;
			ans--;
		}
	}
	cout << ans;
	return 0;
}