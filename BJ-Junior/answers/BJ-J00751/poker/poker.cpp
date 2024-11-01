#include<bits/stdc++.h>
using namespace std;
int n;
string s[120];
map<string,bool> mp;
int main(){
	freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
	cin>>n;
	int tmp=52;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(!mp[s[i]]) tmp--;
		mp[s[i]]=1;
	}
	cout<<tmp<<"\n";
	return 0;
}