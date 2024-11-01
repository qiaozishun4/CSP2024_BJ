#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
long long ans = 1e18 ;
int dp[100005];
int n ;
void dfs(int cur,long long sum,bool step){
	if(sum>ans){
		return ;
	}
	if(cur==1){
		//cout << sum << endl ;
		return ;
	}
	if(cur==0){
		//cout << sum << endl ;
		ans=min(ans,sum) ;
		return ;
	}
	if(step){
		for(int i = 1 ; i <= 9 ; i++){
			if(cur>=a[i]){
			//	cout << sum*10+i << " " ;
				dfs(cur-=a[i],sum*10+i,0);
			}
		}
	}
	for(int i = 0 ; i <= 9 ; i++){
		if(cur>=a[i]){
			//cout << sum*10+i << " " ;
			dfs(cur-=a[i],sum*10+i,0);
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T ;
	cin >> T ;
	while(T--){
		cin >> n ;
		if(n<2){
			cout << -1 << endl ;
			continue;
		}
		if(n==2){
			cout << 1 << endl ;
			continue;
		}
		if(n==3){
			cout << 7 << endl ;
			continue;
		}
		if(n==4){
			cout << 4 << endl ;
			continue;
		}
		if(n==5){
			cout << 2 << endl ;
			continue;
		}
		if(n==6){
			cout << 6 << endl ;
			continue;
		}
		if(n==7){
			cout << 8 << endl ;
			continue;
		}
		if(n%7==0){
			for(int i = 1 ; i <= n/7 ; i++){
				cout << 8 ;
			}
			cout << endl ;
		}
		if(n%7==1){
			for(int i = 1 ; i < n/7 ; i++){
				cout << 8 ;
			}
			cout << 16 ;
			cout << endl ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}
