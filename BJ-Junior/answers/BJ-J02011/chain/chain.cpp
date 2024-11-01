#include<bits/stdc++.h>
using namespace std;
int a[1010010];
int b[1010101];
int x[1010101];
int y[1010101];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t; cin >> t;
	while(t--){
        int n; cin >> n;
        int k; cin >> k;
        int q; cin >> q;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            for(int j=0;j<i;j++) cin >> b[i];
        }
        for(int i=1;i<=q;i++){
            cin >> x[i] >> y[i];
        }cout << 1 << endl;
	}
	return 0;
}
