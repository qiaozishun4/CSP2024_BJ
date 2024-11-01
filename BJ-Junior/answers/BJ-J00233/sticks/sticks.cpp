#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int T, n, tot=7, maxn = 1e5;
string dp[MAXN];

bool cmps(string s1, string s2){
	if (s1.size() > s2.size()) return true;
	if (s2.size() > s1.size()) return false;
	for (int i=0; i<s1.size(); i++){
		if (s1[i]-'0' > s2[i]-'0') return true;
		if (s1[i]-'0' < s2[i]-'0') return false;
	}
	return true;
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	for (int i=1; i<=maxn; i++) dp[i] = "";
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		if (n == 1){
			printf("-1\n");
			continue;
		}
		if (n <= 1000){		
			if (dp[n].size() != 0){
				cout << dp[n] << "\n";
				continue;
			}
			for (int i=tot+1; i<=n; i++){
				if (dp[i-2].size() != 0) dp[i] = dp[i-2]+"1";
				if (dp[i-3].size() != 0 && cmps(dp[i], dp[i-3]+"7")) dp[i] = dp[i-3]+"7";
				if (dp[i-4].size() != 0 && cmps(dp[i], dp[i-4]+"4")) dp[i] = dp[i-4]+"4";
				if (dp[i-5].size() != 0 && cmps(dp[i], dp[i-5]+"2")) dp[i] = dp[i-5]+"2";
				if (dp[i-6].size() != 0 && cmps(dp[i], dp[i-6]+"0")) dp[i] = dp[i-6]+"0";
				if (dp[i-7].size() != 0 && cmps(dp[i], dp[i-7]+"8")) dp[i] = dp[i-7]+"8";
			}
			tot = n;
			cout << dp[n] << "\n";
			continue;
		}		
		if (n%7 == 0){
			for (int i=1; i<=n/7; i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if (n%7 == 1){
			printf("10");
			for (int i=1; i<=((n-8)/7); i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if (n%7 == 2){
			printf("1");
			for (int i=1; i<=((n-2)/7); i++){
				printf("8");
			}	
			printf("\n");
			continue;
		}		
		if (n%7 == 3){
			printf("200");
			for (int i=1; i<=((n-17)/7); i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if (n%7 == 4){
			printf("20");
			for (int i=1; i<=((n-11)/7); i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if (n%7 == 5){
			printf("2");
			for (int i=1; i<=((n-5)/7); i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if (n%7 == 6){
			printf("6");
			for (int i=1; i<=((n-6)/7); i++){
				printf("8");	
			}	
			printf("\n");
			continue;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}