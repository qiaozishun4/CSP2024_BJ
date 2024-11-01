#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main ()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        mp[s] = true;
    }
    cout << 52 - (int)(mp.size());
    return 0;
}
