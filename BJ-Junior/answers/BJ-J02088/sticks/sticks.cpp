#include <bits/stdc++.h>
using namespace std;
const int N = 4e4;
int st[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
string dp[N + 5];
bool Cmp(string x , string y)
{
	if(x.size() != y.size()) return x.size() < y.size();
	return x < y;
}
int main()
{
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	dp[1] = "-1";
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	for(int i = 8;i <= 11;i++)
	{
		string s;
		// 0
		if(dp[i - 6] != "-1") dp[i] = dp[i - 6] + "0";
		
		// 1
		s = dp[i - 2] + "1";
		if(dp[i - 2] != "-1" && Cmp(s , dp[i])) dp[i] = s;
		
		// 2
		s = dp[i - 5] + "2";
		if(dp[i - 5] != "-1" && Cmp(s , dp[i])) dp[i] = s;
		
		// 4
		s = dp[i - 4] + "4";
		if(dp[i - 4] != "-1" && Cmp(s , dp[i])) dp[i] = s;
		
		// 7
		s = dp[i - 3] + "7";
		if(dp[i - 3] != "-1" && Cmp(s , dp[i])) dp[i] = s;
		
		// 8
		s = dp[i - 7] + "8";
		if(dp[i - 7] != "-1" && Cmp(s , dp[i])) dp[i] = s;
	}
	for(int i = 12;i <= N;i++)
	{
		if(i == 17)
		{
			dp[i] = "200";
			continue;
		}
		dp[i] = dp[i - 7] + "8";
	}
	// for(int i = 1;i <= 100;i++) cout << i << ":" << dp[i] << endl;
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}