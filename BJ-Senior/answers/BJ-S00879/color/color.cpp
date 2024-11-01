#include <bits/stdc++.h>
#define int long long
using namespace std;


int T,n;


signed main(){


	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin >> T;
	while(T--){
		
		cin >> n;
		vector<int> a(n+1,0);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		int maxx = 0;
		
		for(int i = 1; i <= n; i++){
			int cc = 0;
			for(int j = i+1; j <= n; j++){
				if(a[i] == a[j]){
					cc = max(cc,a[j]);
				}
			}
			maxx = max(maxx,cc);
		}
		
		cout << maxx << endl;
	}
	
	return 0;
}
