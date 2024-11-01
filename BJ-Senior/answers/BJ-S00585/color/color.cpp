#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=105;
long long t,n,a[N],dp[N][N][N],ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.ans","w",stdout);
	cin>>t;
	while (t--){
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int i=2;i<=n;i++){
			for (int j=0;j<i;j++){
				for (int k=0;k<i;k++){
					if (j==k)
						continue;
					dp[i][i][k]=max(dp[i][i][k],dp[i-1][j][k]+(a[i]==a[j]?a[i]:0));
					dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]+(a[i]==a[k]?a[i]:0));
				}
			}
		}
		for (int i=0;i<=n;i++)
			ans=max(ans,max(dp[n][n][i],dp[n][i][n]));
		cout<<ans<<'\n';
	}
	return 0;
}
