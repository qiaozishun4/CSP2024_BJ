#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
int dp[N], with0[N], weishu[N], ws0[N], last[N];
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ask[55];
int T;

void print(int x){
	if(last[x] == -1){
		printf("%d", dp[x]);
		return ;
	}
	
	print(last[x]);
	printf("%d", dp[x]);
	
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	scanf("%d", &T);
	int n = 0;
	for(int i = 1; i <= T; i ++){
		scanf("%d", &ask[i]);
		n = max(n, ask[i]);
	}
	
	for(int i = 1; i <= n; i ++){
		dp[i] = 0x3f3f3f3f;
		weishu[i] = 0x3f3f3f3f;
	}
	
	dp[2] = 1;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;
	weishu[2] = 1;
	weishu[4] = 1;
	weishu[5] = 1;
	weishu[6] = 1;
	weishu[7] = 1;
	
	for(int i = 1; i <= 7; i ++){
		last[i] = -1;
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < 10; j ++){
			int k = i - a[j];
			if(weishu[k]+1 < weishu[i]){
				weishu[i] = weishu[k] + 1;
				dp[i] = j;
				last[i] = k;
 			}
 			else if(weishu[k]+1 == weishu[i] && dp[k] + a[j] < dp[i]){
				dp[i] = j;
				last[i] = k;
			}
		}
		if(dp[i] == 0) with0[i] = 1;
	}
	
	for(int i = 1; i <= T; i ++){
		if(dp[i] == 0x3f3f3f3f){
			printf("-1\n");
			continue;
		}
 		if(dp[i] != 0) {
			print(ask[i]);
			continue;
		}
		
		int x = ask[i];
		int odp = dp[x], olast = last[x], ows = weishu[x];
		for(int j = 1; j < 10; j ++){
			int k = x - a[j];
			if(weishu[k]+1 < weishu[x]){
				weishu[x] = weishu[k] + 1;
				dp[x] = j;
				last[x] = k;
			}
			else if(weishu[k]+1 == weishu[x] && dp[k] + a[j] < dp[x]){
				dp[x] = j;
				last[x] = k;
			}
		}
		print(x);
		dp[x] = odp, last[x] = olast, weishu[x] = ows;
	}
	return 0;
}
