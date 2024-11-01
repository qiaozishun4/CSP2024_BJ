#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[1000005];
long long dp[1000005];
long long lst[1000005];
long long summ(long long o,long long p){
	long long cnt=0;
	for(long long i = o+1;i<=p;i++){
		if(a[i]==a[i-1]){
			cnt+=a[i];
		}
	}
	return cnt;
}+
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long mx=0;
		for(int i = 0;i<n;i++){
			cin>>a[i];
			mx=max(a[i],mx);
		}
		for(int i = 1;i<=mx+10;i++){
			lst[i]=-1;
		}
		mx=0;
		for(int i = 0;i<n;i++){
			if(lst[a[i]]!=-1){
				dp[i]=max((long long)0,max(dp[lst[a[i]]]+a[i]+summ(lst[a[i]]+1,i-1),dp[lst[a[i]]+1]+a[i]+summ(lst[a[i]]+1,i-1)));
			}else{
				dp[i]=dp[i-1];
			}
			mx=max(mx,dp[i]);
			lst[a[i]]=i;
		}
		cout<<mx<<endl;
	}
	return 0;
}
