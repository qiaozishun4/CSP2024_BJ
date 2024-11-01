#include <bits/stdc++.h>
using namespace std;
long long st[20]={6,2,5,5,4,5,6,3,7,6};
long long dp[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
long long xh[10]={88,108,188,200,208,288,688};
long long T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=21){
			cout<<dp[n]<<endl;
		}else{
			cout<<xh[n%7];
			for(int i=1;i<=n/7-2;i++) cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
//我不配QAQ
