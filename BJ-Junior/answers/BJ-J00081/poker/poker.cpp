#include <iostream>
#include <cstdio>
using namespace std;
int c[200][200];
char d1[5] = {' ','D','C','H','S'};
char d2[15] = {' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        c[s[0]][s[1]] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            if(!c[d1[i]][d2[j]]) ans++;
        }
    }
    cout << ans;
    return 0;
}
