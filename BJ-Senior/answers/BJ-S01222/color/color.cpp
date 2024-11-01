#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200000+10],f[200000+10],ans;
void dfs(long long cur,long long cnt0,long long cnt1,long long sum){
	if(cur>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=0;i<=1;i++){
		f[cur]=i;
		int x=cnt0,y=cnt1,z=sum;
		if(i==0) x++;
		else y++;
		if((i==0&&x==0)||(i==1&&y==0)||cur==1) z+=0;
		else{
			for(int j=cur-1;j>=1;j--){
				if(f[j]==i){
					if(a[j]==a[cur]) z+=a[cur];
					break;
				}
			}
		}
		dfs(cur+1,x,y,z);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ans=0;
		dfs(1,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
