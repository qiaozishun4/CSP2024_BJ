#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int>mp;
int n,t,mx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		mp[t]++;
	}
	for(auto i:mp)
		mx=max(mx,i.second);
	cout<<mx;
	return 0;
}
