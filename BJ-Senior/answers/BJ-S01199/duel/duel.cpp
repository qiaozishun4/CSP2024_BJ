#include<bits/stdc++.h>
using namespace std;
int a[100005],t[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,idx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) idx++;
		t[idx]++;
	}
	for(int i=2;i<=idx;i++){
		if(t[i]<=t[i-1]) t[i]+=t[i-1]-t[i];
	}
	cout<<t[idx];
	return 0;
}