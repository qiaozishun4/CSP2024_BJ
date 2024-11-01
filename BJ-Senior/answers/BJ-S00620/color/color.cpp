#include<bits/stdc++.h>
using namespace std;
int T,n;
long long a[100005],f[2005][2005][2];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T,a[0]=-1;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		memset(f,0,sizeof(f));
		for(int i=2;i<=n;++i){
			for(int j=1;j<=i;++j){
				if(j>1){
				f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]+(a[i]==a[i-1])*a[i]);
				f[i][j][0]=max(f[i][j][0],f[i-1][j-1][0]+(a[i]==a[i-1])*a[i]);
				}
				if(i-j){
				f[i][1][0]=max(f[i][1][0],f[i-1][j-1][1]+(a[i]==a[i-j])*a[i]);
				f[i][1][1]=max(f[i][1][1],f[i-1][j-1][0]+(a[i]==a[i-j])*a[i]);
				}
			}
		}/*
		for(int i=2;i<=n;++i){
			for(int j=1;j<=i;++j){
				cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<"\n";
			}
		}*/
		long long ans=0;
		for(int i=1;i<=n;++i) ans=max(ans,max(f[n][i][0],f[n][i][1]));
		cout<<ans<<"\n";
	}
	return 0;
}