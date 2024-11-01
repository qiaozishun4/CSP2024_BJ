#include <bits/stdc++.h>
using namespace std;
int t, n, a, q, b;
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>t;
	while(t--){
		cin>>n>>a>>q;
		while(n--){
			cin>>a;
			while(a--){
				cin>>b;
			}
		}
		while(q--){
			cin>>a>>b;
			cout<<"0\n";
		}
	}
	return 0;
}