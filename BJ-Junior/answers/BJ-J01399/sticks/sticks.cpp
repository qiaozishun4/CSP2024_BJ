#include <iostream>
#include <string>
#include <map>
using namespace std;
int t, n, book[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, all[] = {2, 3, 4, 5, 6, 7};
string dp[100005];
template<typename... Args>void print(Args... args){int write[] = {(cout << args, 0)...};}
int cmp(string a, string b)
{
	if(a.size() <= b.size())
	{
		if(a.size() < b.size()) return 1;
		else
		{
			for(int i = 0; i < a.size(); i++)
			{
				if(a[i] < b[i]) return 1;
				else if(a[i] > b[i]) return 0;
			}
			return -1;
		}
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		for(int i = 0; i <= 100003; i++) dp[i] = "";
		cin >> n;
		for(int i = 0; i <= n; i++)
		{
			if(i <= 1) dp[i] = "";
			else if(i <= 7)
			{
				if(i == 2)
				{
					dp[i] = "1";
				}
				else if(i == 3)
				{
					dp[i] = "7";
				}
				else if(i == 4)
				{
					dp[i] = "4";
				}
				else if(i == 5)
				{
					dp[i] = "2";
				}
				else if(i == 6)
				{
					dp[i] = "6";
				}
				else if(i == 7)
				{
					dp[i] = "8";
				}
			}
			else
			{
				for(int j = 0; j <= 9; j++)
				{
					if(i - book[j] <= 0) continue;
					string now;
					for(int k = 0; k < dp[i].size() - 1; k++) now += dp[i][k];
					if(cmp(dp[i - book[j]], now) == 0)
					{
						now += j + '0';
						dp[i] = now;
					}
					else
					{
						string kk = dp[i - book[j]];
						kk += j + '0';
						dp[i] = kk;
					}

				}
			}
		}
		cout << (dp[n] == "" ? "-1" : dp[n]) << endl;
	}
	return 0;
}