#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[50005],dp[50005];
	cin>>n;
	int ans=n;
	for(int i = 0;i < n; i++){
        cin>>a[i];
        dp[i]=a[i];
	}
	sort(a,a+n);
	sort(dp,dp+n);
	for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            if(dp[j]<=a[i]){
                continue;
            }else if(a[i]==-1||dp[j]==-1){
                break;
            }else{
                ans--;
                a[i]=-1;
                dp[j]=-1;
                break;
            }
        }
	}
	cout<<ans<<endl;
	return 0;
}