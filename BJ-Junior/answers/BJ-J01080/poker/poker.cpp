#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
map<string,long long> mp;
map<string,long long> cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		mp[s]++;
	}
	int ans=52;
	for(auto it : mp){
		if(cnt[it.first]==0){
			ans--;
			cnt[it.first]=1;
		}
	}
	cout<<ans;
	return 0;
}
