#include<bits/stdc++.h>
using namespace std;
int h[]={6,2,5,5,4,5,6,3,7,6};
int ans=1e9;
void dfs(int f,int x,int sum){
	if(x==f){
		if(sum!=0) ans=min(ans,sum);
		return ;
	}
	for(int i=0;i<=9;i++){
		if(x==0&&i==0) continue;
		if(h[i]+x<=f){
			dfs(f,x+h[i],sum*10+i);
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		dfs(n,0,0);
		if(ans==1e9) cout<<-1<<endl;
		else cout<<ans<<endl;
		ans=1e9;
	}
	return 0;
}
