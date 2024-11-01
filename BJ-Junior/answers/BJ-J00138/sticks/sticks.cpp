#include <bits/stdc++.h>
using namespace std;
long long w[110] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
long long v[110] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
string dp[100010] = {"-1" , "-1" , "1" , "7" , "4" , "2" , "6" , "8" , "10" , "18" , "23" , "20" , "28"};
string made(long long x)
{
    string ans = dp[x - 7];
    ans = ans + "8";
    return ans;
}
int main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
	long long T;
	cin >> T;
	while(T--)
    {
        long long n;
        cin >> n;
        if(n < 12)
        {
            cout << dp[n] << endl;
        }
        else
        {
            for(long long i = 12 ; i <= 100 ; i ++)
            {
                dp[i] = made(i);
            }
            long long d = (n - 7) / 7;
            cout << dp[n - d * 7];
            for(long long i = 1 ; i <= d ; i ++)
            {
                printf("8");
            }
            cout << endl;
        }
    }
	return 0;
}
