#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N],h[N],b[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[a[i]]++;
	}
	int k=1;
	for(int i=1;i<=100010;i++){
		if(h[i]!=0){
			b[k++]=i;
		}
	}
	int ans=0;
	int o=min(h[b[2]],h[b[1]]);
	int q=max(h[b[2]],h[b[1]]);
	ans+=o;
	o=q;
	q=0;
	for(int i=3;i<k;i++){
		q=max(o,h[b[i]]);
		o=min(o,h[b[i]]);
		ans+=o;
		o=q;
		q=0;
	}
	cout<<n-ans;
	return 0;
}
