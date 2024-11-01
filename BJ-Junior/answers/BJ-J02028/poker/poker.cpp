#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	while(n--){
		cin >> s;
		mp[s]= 1;
	}
	cout << 52 - mp.size();
	return 0;
}
