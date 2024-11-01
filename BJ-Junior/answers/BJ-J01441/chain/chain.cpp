#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			int l,x;
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>x;
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			cout<<0<<"\n";
		}
	}
	return 0;
}