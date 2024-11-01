#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

vector<int>G[2];
int T,n,ans,cnt,a[N],col[N];
void dfs(int x,int y){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j;j--){
				if(col[i]==col[j]){
					cnt+=(a[i]==a[j])*a[i];
					break;
				}
			}
		}
		ans=max(ans,cnt);
		return;
	}
	col[x]=y;
	dfs(x+1,0);
	dfs(x+1,1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(1,0);
		dfs(1,1);
		cout<<ans<<endl;
	}
	return 0;
}
