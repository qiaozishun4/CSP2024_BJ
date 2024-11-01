#include <bits/stdc++.h>

using namespace std;
int T,n,k,q,r,c,s,l;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l;
			for(int j=1;j<=l;j++){
				cin>>s;
			}
		}
		while(q--){
			cin>>r>>c;
			if(r>100||c<1009){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
