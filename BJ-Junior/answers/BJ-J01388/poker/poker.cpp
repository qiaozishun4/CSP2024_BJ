#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
string s;
int cnt=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	while(cin>>s){
		mp[s]=true;
	}
	for(auto i:mp){
		cnt++;
	}
	if(cnt>52)cout<<0;
	else cout<<52-cnt+1;
	return 0;
}
