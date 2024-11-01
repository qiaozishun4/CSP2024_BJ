#include <bits/stdc++.h>
using namespace std;
int ans;
int ii,ai;
int a[100005];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ii=1;
	ai=a[1];
	int m;
	for(int i=n;i>1;i--){
		for(int j=2;j<=n;j++){
			if(a[j]<a[j-1]){
				m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]>ai){
			ii++;
			ai=a[ii];
			ans++;
		}
	}
	cout<<n-ans;
	return 0;
}
