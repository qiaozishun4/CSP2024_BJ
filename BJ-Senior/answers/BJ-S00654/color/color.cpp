#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int t;
int n;
int a[N],f[N];
long long ans=0;
void dfs(int c,int deep){
	f[deep]=c;
	if(deep==n){
		long long k=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(f[j]==f[i]&&a[j]==a[i]){
					k+=a[i];
					break;
				}
			}
		}
		ans=max(ans,k);
		return;
	}
	dfs(0,deep+1);
	dfs(1,deep+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >>t;
	while(t--){
		ans=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		dfs(0,1);
		dfs(1,1);
		cout<<ans<<endl;
	}
	return 0;
}
