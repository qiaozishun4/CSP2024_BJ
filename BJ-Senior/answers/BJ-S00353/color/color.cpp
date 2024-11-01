#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[100010],h[100010];
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			h[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			h[a[i]]++;
		}
		int ans=0;
		bool vis[100010];
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==0){
				ans+=(h[a[i]]-1)*a[i];
				vis[a[i]]=1;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
