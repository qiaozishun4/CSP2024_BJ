#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,a[N],ans,c[N];
bool bt[N];
ll sigma(){
	ll res=0;
	for(ll i=1;i<=n;i++) res+=c[i];
	return res;
}
void dfs(ll cur){
	if(cur>n){
		for(ll i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(bt[j]==bt[i]){
					if(a[i]==a[j]){
						c[i]=a[i];
					}
					else c[i]=0;
					break;
				}
			}	
		}
		ans=max(ans,sigma());
		return;
	}
	for(ll i=0;i<=1;i++){
		bt[cur]=i;
		dfs(cur+1);
	}
}
int main(){
	freopen("color.in.in","r",stdin);
	freopen("color.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(c,0,sizeof c);
		ans=0;
		memset(bt,0,sizeof bt);
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
