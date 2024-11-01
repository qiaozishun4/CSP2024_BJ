#include<bits/stdc++.h>
using namespace std;
int a[20],c[20],tag[20],n;
int dfs(int k){
	if(k==n+1){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(tag[j]==tag[i]&&a[i]==a[j])
					ans += a[i];
			}
		}
		return ans;
	}
	tag[k] = 1;
	int d = dfs(k+1);
	tag[k] = 0;
	int b = dfs(k+1);
	return max(d,b);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<dfs(1)<<endl;
	}
	return 0;
}