#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
set<string> st;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		st.insert(s);
	}
	ll len=st.size();
	cout<<52-len;
	return 0;
}
