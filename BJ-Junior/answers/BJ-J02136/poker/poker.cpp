#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool h[300][300];
signed main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	ans=52;
	while(n--){
		string s;
		cin>>s;
		if(h[s[0]][s[1]]!=1) h[s[0]][s[1]]=1,ans--;
	}
	cout<<ans;
	return 0;
}
