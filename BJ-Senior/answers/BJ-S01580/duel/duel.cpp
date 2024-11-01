#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int duelvalue[100005];

bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>duelvalue[i];
	sort(duelvalue,duelvalue+n,cmp);
	if(duelvalue[0]==duelvalue[n-1]){
		cout<<n;
		return 0;
	}
	int lmon=0,rmon=1,ans=n;
	while(rmon!=n){
		if(duelvalue[lmon]==duelvalue[n-1])break;
		while(duelvalue[rmon]<=duelvalue[lmon])rmon++;
		lmon++;
		rmon++;
		ans--;
	}
	cout<<ans;
	return 0;
}
