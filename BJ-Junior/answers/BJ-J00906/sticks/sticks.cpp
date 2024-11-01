#include <bits/stdc++.h>
#define int long long
using namespace std;

int t , m[90] = {0 , 0 , 1 , 7 , 4 , 2 , 0 , 8} , rm[100] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6} , road[1005] , cnt = 0;
string minn = "100000000000000000000000000000000000000000";

string minstr(string x , string y)
{
    if(x.length() != y.length())
    {
        if(x.length() < y.length()) return x;
        else return y;
    }
    if(x < y) return x;
    else return y;
}
void dfs(int x , int remain)
{
    if(x == 0)
    {
        if(remain == 0)
        {
            string sum = "";
            for(int i = 1; i <= cnt; i++) {sum = sum + char('0' + m[road[i]]);/*cout << char('0' + m[road[i]]);*/}
            if(sum[0] == '0') sum[0] = '6';
            minn = minstr(minn , sum);
        }
        return;
    }
    for(int i = 2;i <= 7; i++)
    {
        road[x] = i;
        dfs(x - 1 , remain - i);
        road[x] = 0;
    }
}
signed main()
{
    freopen("sticks.in" , "r" , stdin);
    freopen("sticks.out" , "w" , stdout);
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n % 7 == 0)
        {
            for(int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl;
            continue;
        }
        else if(n == 1)
        {
            cout << -1 << endl;
        }
        else if(n % 7 == 1)
        {
            cout << 10;
            for(int i = 1; i <= (n - 1) / 7 - 1; i++) cout << 8;
            cout << endl;
        }
        else if(n <= 50)
        {
            minn = "1000000000000000000000000000000";
            int x = n / 7;
            cnt = x + 1;
            dfs(x + 1 , n);
            cout << minn << endl;
        }
        else
        {
            int x = n % 7 , y = n / 7;
            int z = y * 7 + 1;
            string s = "10";
            for(int i = 1; i <= (z - 1) / 7 - 1; i++) s = s + "8";
            for(int i = 2; i <= x; i++)
            {
                for(int j = s.length() - 1; j >= 0; j--)
                {
                    if(s[j] != '8') {s[j] = m[rm[(s[j] - '0')] + 1];break;}
                }
                //if(!flag) s[0] = (s[0] - '0')
            }
            cout << s << endl;
        }
    }
    return 0;
}
