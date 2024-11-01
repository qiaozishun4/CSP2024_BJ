#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,res = 52;
set<string> st;

signed main(){
	
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		if(st.find(s) == st.end()){
			st.insert(s);
			res--;
		}
		
	}
	cout << res << endl;
	
	return 0;
	
}
