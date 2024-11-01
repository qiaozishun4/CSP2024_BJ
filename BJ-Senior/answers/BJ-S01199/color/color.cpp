#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL ans;
int a[200005];
bool tmp[200005];
void dfs(int x){
	if(x==n+1){
		int r=-1,b=-1;
		LL sum=0;
		for(int i=1;i<=n;i++){
			if(r!=-1 && !tmp[i] && a[r]==a[i]) sum+=a[i];
			if(b!=-1 && tmp[i] && a[b]==a[i]) sum+=a[i];
			if(!tmp[i]) r=i;
			if(tmp[i]) b=i;
		}
		ans=max(ans,sum);
		return ;
	}
	tmp[x]=0;
	dfs(x+1);
	tmp[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}