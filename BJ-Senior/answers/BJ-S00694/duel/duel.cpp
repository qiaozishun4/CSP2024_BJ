#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=0;
	}
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,mp[a[i]]);
	}
	cout<<ans;		

	return 0;
}
