#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],red[200005],blue[200005],hz[200005],ans;
void dfs(int ii,int fs){
	if(hz[ii]+fs<ans){
		return;
	}
	if(ii>n){
		ans=max(ans,fs);
		return;
	}
	red[ii]=red[ii-1];
	blue[ii]=blue[ii-1];
	red[ii]=ii;
	dfs(ii+1,fs+(a[red[ii-1]]==a[ii])*a[ii]);
	red[ii]=red[ii-1];
	blue[ii]=ii;
	dfs(ii+1,fs+(a[blue[ii-1]]==a[ii])*a[ii]);
	blue[ii]=blue[ii-1];
	return;
}
void sv(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=n;i>=1;i--){
		hz[i]=hz[i+1]+a[i];
	}
	ans=0;
	dfs(1,0);
	cout << ans << "\n";
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		sv();
	}
	return 0;
}
