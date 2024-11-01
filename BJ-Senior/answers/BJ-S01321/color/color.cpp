#include<bits/stdc++.h>
using namespace std;
long long f[111][111][111];
long long t;
int n;
int num[111];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		memset(num,0,sizeof num);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)cin>>num[i];
		for(int j=n;j>=1;j--){
			for(int i=j+1;i<=n+1;i++){
				for(int q=j+1;q<=n+1;q++){
					if(i==q)continue;
					f[j][j][q]=max(f[j][j][q],f[j+1][i][q]+((num[i]==num[j])?num[i]:0));
					f[j][i][j]=max(f[j][i][j],f[j+1][i][q]+((num[q]==num[j])?num[q]:0));
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				for(int k=1;k<=n+1;k++)ans=max(ans,f[i][j][k]);
			}
		}
		cout<<ans<<endl;
	}
return 0;
}
