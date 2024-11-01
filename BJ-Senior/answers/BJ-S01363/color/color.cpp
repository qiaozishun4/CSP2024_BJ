#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int dp[N];
int t;
int a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=2;i<n;i++){
			for(int j=1;j<i;j++){	
				if(a[i]==a[i-j]){
					dp[i]=a[i];
				}
				else dp[i]=0;
			}
			sum+=dp[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}