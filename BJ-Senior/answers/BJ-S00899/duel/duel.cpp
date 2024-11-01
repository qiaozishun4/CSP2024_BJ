#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int r=0;
	for(int l=1;l<=n;l++){
		r++;
		while(r<=n&&a[r]<=a[l]){
			r++;
		}
		if(r==n+1){
			break;
		}
		ans--;
	}
	cout<<ans;
	return 0;
}
