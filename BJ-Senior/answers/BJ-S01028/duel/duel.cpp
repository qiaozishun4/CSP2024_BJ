#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	int sum=0;
	int u=0;
	for(int i=1;i<=100000;i++){
		if(a[i]==0) continue;
		sum+=min(u,a[i]);
		u=max(u,a[i]);
	}
	cout<<n-sum;
	return 0;
}
