#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set<string> s;
	ll n;
	string st;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>st;
		s.insert(st);
	}
	cout<<52-s.size();
	return 0;
}