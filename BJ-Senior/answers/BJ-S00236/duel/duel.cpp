#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		if(a[r]>a[l]){
			l++;
		}
		r++;
	}
	cout<<r-l;
	return 0;
}

