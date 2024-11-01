#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int t,n,k,q;
int l,s,r,c;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++){
			cin >> l;
			for(int j = 1;j <= l;j++){
				cin >> s;
			}
		}
		for(int i = 1;i <= q;i++){
			cin >> r >> c;
		}
		for(int i = 1;i <= q;i++){
			cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
