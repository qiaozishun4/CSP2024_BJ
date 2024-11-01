#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int n;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d", &n);
    while (n--)
    {
        cin >> s;
        mp[s] = 1;
    }
    printf("%d", 52 - mp.size());
    return 0;
}
