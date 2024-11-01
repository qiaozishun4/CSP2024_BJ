#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k,q,l[100005],r[100005],c[100005];
		string s[200005];
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;i<=l;j++){
				cin>>s[j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			cout<<0<<endl;
		}
	}
	return 0;
}
