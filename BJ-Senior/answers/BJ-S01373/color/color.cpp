#include<bits/stdc++.h>
using namespace std;
int t,n,box[1000];
bool vis[10005];
int a[200005],ans=0;
int js(int k){
	for(int i=k-1;i>=1;i--){
		if(box[k]==box[i]){
			if(a[k]==a[i]){
				return a[i];
			}
			else{
				return 0;
			}
		}
	}
	return 0;
}
void dfs(int cur){
	if(cur>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=js(i);
		}
		ans=max(sum,ans);
		return;
	}
	for(int i=0;i<=1;i++){
		box[cur]=i;
		dfs(cur+1);
	}
}
void s(){
	for(int i=2;i<=n;i++){
		for(int j=i-1;j<=n;j++){
			if(vis[i]==vis[j]){
				if(a[i]==a[j]){
					ans+=a[i];
					vis[i]=1;
					vis[j]=1;
				}	
				else i=3;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=15){
			dfs(1);
			cout<<ans<<endl;		
		}
		else{
			s();
		}
	}
	return 0;
}

