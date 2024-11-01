#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n;
long long ans=0;
long long a[N];

void dfs(int cur,long long sum,int ltr,int ltb){ //cur,sum ,last red,last blue
	if(cur>n){
		ans=max(ans,sum);
		return ;
	}
	if(a[cur]==a[ltr]) dfs(cur+1,sum+a[cur],cur,ltb);
	else dfs(cur+1,sum,cur,ltb);
	if(a[cur]==a[ltb]) dfs(cur+1,sum+a[cur],ltr,cur);
	else dfs(cur+1,sum,ltr,cur);
	return ;
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
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
