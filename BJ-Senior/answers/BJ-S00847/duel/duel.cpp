#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int r=1;r<=n;++r){
		if(a[l]<a[r])l++;
	}
	cout<<n-l+1;
	return 0;
}
