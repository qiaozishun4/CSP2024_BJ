#include<bits/stdc++.h>
using namespace std;
int a[200005];
int color[200005];
map<int,vector<int> > v;
int n;
int ans;
void dfs(int x){
	if(x==n+1) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			
			for(int j=i-1;j>0;j--){
				if(color[j]==color[i]){
					if(a[j]==a[i]) {
						cnt+=a[i];
						//~ cout<<"#########################"<<i<<' '<<j<<'\n';
					}
					break;
				}
			}
		}
		//~ for(int i=1;i<=n;i++){
			//~ cout<<color[i]<<' ';
		//~ }
		//~ cout<<cnt<<'\n';
		ans=max(ans,cnt);
		return ;
	}
	color[x]=0;
	dfs(x+1);
	color[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w", stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
