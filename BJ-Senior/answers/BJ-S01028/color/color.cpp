#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int t,n;
bool b[N];
int ans;
void check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(b[i]==b[j]){
				if(a[i]==a[j]) sum+=a[i];
				break;
			}
		}
	}
	ans=max(ans,sum);
}
void dfs(int d){
	if(d==n){
		check();
		return ;
	}
	b[d+1]=0;
	dfs(d+1);
	b[d+1]=1;
	dfs(d+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=-1;
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}
