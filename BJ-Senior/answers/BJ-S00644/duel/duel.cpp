#include<iostream>
using namespace std;
int n,a[100005],h[100005],cc;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[a[i]]++;
	}
	for(int i=1;i<=100000;i++){
		int t=min(cc,h[i]);
		h[i]-=t;
		n-=t;
		if(h[i]){
			cc+=h[i];
		}
	}
	cout<<n;
	return 0;
}
