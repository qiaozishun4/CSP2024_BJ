#include<bits/stdc++.h>
using namespace std;

map <string,bool> mp;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int sum=52;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        if (!mp[s]) sum--;
        mp[s]=true;
    }
    cout << sum << endl;

    return 0;
}
