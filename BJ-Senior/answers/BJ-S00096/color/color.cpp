//expect 20pts
#include<bits/stdc++.h>
using namespace std;
int T,n,a[20];
bool color[20];
int ans;
void dfs(int x){
	if(x>n){
		//0=red,1=blue
		int cur=0;
		int lastRed=-1,lastBlue=-1;
		for(int i=1;i<=n;i++){
			if(color[i]){
				//blue
				if(lastBlue==a[i])cur+=a[i];
				lastBlue=a[i];
			}else{
				//red
				if(lastRed==a[i])cur+=a[i];
				lastRed=a[i];
			}
		}
		if(cur>ans)ans=cur;
		return;
	}
	color[x]=0;
	dfs(x+1);
	color[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
}