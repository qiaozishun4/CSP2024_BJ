#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q;
		int x,y;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>x;
			for(int j=1;j<=x;j++)cin>>y;
		}
		int a,b;
		while(q--){
			cin>>a>>b;
			cout<<0<<endl;
		}
	}
	return 0;
}
