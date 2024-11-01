#include <bits/stdc++.h>
using namespace std;

string dp[100010] = {"","","1","7","4","2","6","8","10","18","22","20","28","68","88"};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1 or n == 0) cout <<-1 << endl;
        else if (n <= 14) cout << dp[n] << endl;
        else if (n % 7 == 0)
        {
            for (int i = 1;i <= n / 7;i++) cout << 8;
            cout << endl;
        }
        else
        {
            cout << dp[n % 7 + 7];
            for (int i = 2;i <= n / 7;i++) cout << 8;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}