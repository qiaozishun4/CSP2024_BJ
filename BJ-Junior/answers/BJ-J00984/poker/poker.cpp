#include<bits/stdc++.h>

using namespace std;
int n;
map<string, int> mp;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i ++ )
    {
        string s;
        cin >> s;
        if(mp[s] == 0)
        {
            ans ++ ;
        }
        mp[s] ++ ;
    }
    cout << 52 - ans << endl;
	return 0;
}
