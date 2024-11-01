#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,k,q;
		bool flag=0;
		cin >> n >> k >> q;
		for(int i=1;i<=n;++i){
			int l;
			cin >> l;
			for(int j=1;j=l;++j){
				string s;
				cin >> s;
				if(s[0]=='1') flag=1;
			}
		}
		for(int i=1;i<=q;++i){
			cout << (flag?1:0) << endl;
		}
	}
	return 0;
}
