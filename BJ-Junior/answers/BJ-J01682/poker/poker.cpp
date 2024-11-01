#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int cnt = 52;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) cnt--;
    printf("%d\n", cnt);
    return 0;
}
