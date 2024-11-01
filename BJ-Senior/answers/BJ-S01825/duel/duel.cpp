#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 7;
int r[MX];multiset<int > s;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;cin >> n;
	for(int i = 1;i <= n;i++)cin >> r[i];
	sort(r + 1,r + 1 + n);
	for(int i = 1;i <= n;i++){
		auto it = s.lower_bound(r[i]);
		if(it != s.begin()){it--;s.erase(it);}
		s.insert(r[i]);
	}
	cout << s.size() << '\n';
	return 0;
}