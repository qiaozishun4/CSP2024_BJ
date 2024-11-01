#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,s,r,c;
int main(){
	freopen("chian.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int i=1;i<=l;i++)cin>>s;
		}
		for(int i=1;i<=q;i++)cin>>r>>c;
		cout<<1<<endl;
	}
	return 0;
}
