#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	map<string,int> mp;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(mp[s]==1) cnt--;
		mp[s]=1;
		cnt++;
	}cout<<52-cnt;
	return 0;
}