#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n;


signed main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin >> t;
	while(t--){
		
		cin >> n;
		if(n <= 1){
			cout << -1 << endl;
			continue;
		}
		if(n == 2){
			cout << 1 << endl;
			continue;
		}
		
		if(n%7 == 0){
			for(int i = 1; i <= n/7; i++){
				cout << 8 ;
			}
			cout << endl;
			continue;
		}
		
		
	}
		
		
	
	
	return 0;
	
}
