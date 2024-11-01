#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,m=1e5;
int n,a[N],nw,mx;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		mx=max(mx,x);
	}
	for(int i=1;i<=mx;i++){
		nw=max(0,nw-a[i]);
		nw+=a[i];
	}
	cout<<nw;
	return 0;
}
