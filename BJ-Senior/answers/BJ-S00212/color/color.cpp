#include<bits/stdc++.h>
using namespace std;
int mp[100001]={};
int a[100001]={};
long long ans=0,n;
void check11(){
	long long ansa=0;
	int lr=0,lb=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(mp[i]==lr){
				ansa+=lr;
			}
			lr=mp[i];
		}else{
			if(mp[i]==lb){
				ansa+=lb;
			}
			lb=mp[i];
		}
	}
	ans=max(ans,ansa);
}
void dfs(int m){
	if(m==n+1){
		check11();
		return ;
	}
	a[m]=0;
	dfs(m+1);
	a[m]=1;
	dfs(m+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
