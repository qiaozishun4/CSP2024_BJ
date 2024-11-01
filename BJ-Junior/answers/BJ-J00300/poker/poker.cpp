#include<bits/stdc++.h>
using namespace std;
set<string> s;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string t;
	for(int i=1;i<=n;i++){
		cin>>t;
		s.insert(t);
	}
	int ans=52;
	set<string> :: iterator it;
	for(it=s.begin();it!=s.end();it++){
		ans--;
	}
	cout<<ans;
}
