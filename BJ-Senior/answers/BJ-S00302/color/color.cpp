#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
int T,n;
int a[N];
int h[M];
bool c[N];
long long ans,res;
void dfs(int step){
	if(step==n+1){
		res=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(c[i]==c[j]){
					if(a[i]==a[j]) res+=a[i];
					break;
				}
			}
		}
		ans=max(ans,res);
		return ;
	}
	for(int i=0;i<=1;i++){
		c[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		if(n<=15){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			dfs(1);
		}
		else{
			memset(h,0,sizeof(h));
			for(int i=1;i<=n;i++){
				cin>>a[i];
				h[a[i]]++;
			}
			for(int i=1;i<=n;i++){
				if(h[a[i]]){
					ans+=a[i]*(h[a[i]]-1);
					h[a[i]]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}