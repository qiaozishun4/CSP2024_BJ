#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
int T,n,cnt=0,a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1) cout<<0<<endl;
		else if(n==2){
			if(a[1]==a[2]) cout<<a[1]<<endl;
			else cout<<0<<endl;
		}
		else{
			cout<<a[n]<<endl;
		}
	}
	return 0;
}