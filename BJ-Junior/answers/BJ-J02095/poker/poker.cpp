#include<bits/stdc++.h>
using namespace std;

int zx[1000005];
int n;
char ac[4] = {'D', 'C', 'H', 'S'};
char bc[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        char a = t[0], b = t[1];
        int cnt = 0;
        for(int i = 0; i <= 3; i++)
        {
            if(ac[i] == a)
            {
                cnt += i;
                break;
            }
        }
        for(int i = 0; i <= 12; i++)
        {
            if(bc[i] == b)
            {
                cnt = cnt * 13 + i;
                break;
            }
        }
        zx[cnt] = 1;
    }
    int ans = 0;
    for(int i = 0; i <= 51; i++)
    {
        if(zx[i] == 0)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
