#include<bits/stdc++.h>
using namespace std;
multiset<pair<int,int>> A,B;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n,k;
	cin>>n,k=n;
	for(int i=0,x;i<n;++i)
		cin>>x,A.insert({x,i}),B.insert({x,i});
	while(1){
		auto a=A.upper_bound({B.begin()->first+1,0});
		if(a==A.end()) break;
		A.erase(a);
		A.erase(*B.begin());
		B.erase(B.begin());
		--k;
	}
	cout<<k;
}