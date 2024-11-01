#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 52;
map<string,int> m;
string s1 = "0DCHS",s2 = "0A23456789TJQK";
int n;

signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int ans = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            string t;
            t += s1[i];
            t += s2[j];
            if(!m[t]) ans++;
        }
    }
    cout << ans;
    return 0;
}
