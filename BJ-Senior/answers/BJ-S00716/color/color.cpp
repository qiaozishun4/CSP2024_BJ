#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200005];
int ans1[200005]={1,2,1};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int x;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			x=max(x,a[i]);
		}
		cout<<x+a[n];
	}
	return 0;
}
