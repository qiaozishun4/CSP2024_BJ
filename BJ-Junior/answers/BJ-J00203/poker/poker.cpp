#include <bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << 52 - (int)s.size();
    return 0;
}