// #define debug
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10 ;
const int cnt[]={6,2,5,5,4,5,6,3,7,6};

int t,n,mx,dp[N];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>t;
	while(t--){
		cin>>n;
        dp[0]=0;
		for(int i=mx;i<=n;i++){
            #ifdef debug
            cout<<"dp["<<i<<"]="<<dp[i]<<endl;
            #endif
			for(int j=0;j<10;j++){
                #ifdef debug
                cout<<"-> "<<i+cnt[j]<<" ("<<j<<")"<<endl;
                #endif
                if(!i && !j){
                    continue;
                }
				dp[i+cnt[j]]=min(dp[i+cnt[j]],dp[i]*10+j);
			}
		}
		mx=max(mx,n);
		if(n==1){
			cout<<-1<<endl;
		}else{
			cout<<dp[n]<<endl;
		}
	}
	return 0;
}
