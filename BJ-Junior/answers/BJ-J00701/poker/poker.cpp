#include<bits/stdc++.h>
using namespace std;
set<string> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		mp.insert(s);
	}
	cout<<52-mp.size();
	return 0;
}
