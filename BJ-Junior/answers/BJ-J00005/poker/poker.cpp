#include<bits/stdc++.h>
using namespace std;

string s[52] = {"DA", "CA", "HA", "SA",
                "D2", "C2", "H2", "S2",
                "D3", "C3", "H3", "S3",
                "D4", "C4", "H4", "S4",
                "D5", "C5", "H5", "S5",
                "D6", "C6", "H6", "S6",
                "D7", "C7", "H7", "S7",
                "D8", "C8", "H7", "S7",
                "D9", "C7", "H7", "S7",
                "DT", "CT", "HT", "ST",
                "DJ", "CJ", "HJ", "SJ",
                "DQ", "CQ", "HQ", "SQ",
                "DK", "CK", "HK", "SK"};
map<string, bool>mp;
int n, ans;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[s] = true;
    }
    for(int i = 0; i < 52; i++)
    {
        if(mp.count(s[i])) continue;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}