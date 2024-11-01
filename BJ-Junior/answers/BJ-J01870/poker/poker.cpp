#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
map<string,bool> mp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		string x;
		cin>>x;
		if(mp[x]==false){
			ans++;
		}
		mp[x]=true;	
	}	
	cout<<52-ans;
	
	return 0;
}	
