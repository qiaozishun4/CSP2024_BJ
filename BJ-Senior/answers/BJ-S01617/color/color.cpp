#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,cc[1000009],ans=-1;

void dfs(int now,vector<int>&a,vector<int>&col){
	if(now>n){
		vector<int>c(n+1,0);
		int res=0;
		
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(col[j]==col[i]){
					if(a[i]==a[j]){
						c[i]=a[i];
					}
					break;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			res+=c[i];
		}
		
		ans=max(ans,res);
		
		return;
	}
	
	col[now]=1;
	dfs(now+1,a,col);
	col[now]=0;
	dfs(now+1,a,col);
	col[now]=-1;
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int t;
	
	cin>>t;
	
	while(t--){
		int maxx=-1;
		bool f=false;
		ans=-1;
		memset(cc,0,sizeof(cc));
		
		cin>>n;
		
		vector<int>a(n+1,0);
		vector<int>col(n+1,-1);
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cc[a[i]]++;
			maxx=max(maxx,a[i]);
		}
		
		for(int i=0;i<=maxx;i++){
			if(cc[i]>1){
				dfs(1,a,col);
				f=true;
				break;
			}
		}
		
		if(f){
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
