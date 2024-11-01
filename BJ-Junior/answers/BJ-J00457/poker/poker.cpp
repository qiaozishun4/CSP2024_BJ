#include<bits/stdc++.h>
using namespace std;
int n, cnt;
map<string, int> mp;
string a[5] = {" ", "D", "C", "H", "S"};
string b[14] = {" ", "A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            string t = a[i]+b[j];
            if(mp[t] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
