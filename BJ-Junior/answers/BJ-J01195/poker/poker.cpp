#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
	set<string>st;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string x;cin>>x;
		st.insert(x);
	}
	cout<<(52-(int)st.size());
	return 0;
}