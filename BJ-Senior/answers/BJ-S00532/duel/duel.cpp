#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[100005],id=0,ans=0;
	bool vis[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	r[0]=-1;
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(r[i]>r[id]){
			vis[id]=1;
			for(int j=id+1;j<=i;j++){
				if(!vis[j]){
					id=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}