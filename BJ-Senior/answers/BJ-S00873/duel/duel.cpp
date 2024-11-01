#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int j=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[j]<a[i]){
			ans++;
			j++;
		}
	}
	cout<<n-ans;
	return 0;
}
