#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("chain.in","r",stdin);
	//freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k,q,m,ans=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>m;
			ans+=m;
		}
		for(int i=1;i<=q;i++){
			cin>>m;
			ans+=m;
		}
		if(ans%2==0){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}

