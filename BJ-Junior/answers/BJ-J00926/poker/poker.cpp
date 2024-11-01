#include <bits/stdc++.h>
using namespace std;
int n;
int tong[100][100];
string s;
int ans;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> s;
        int p,q;
        if(s[0] == 'D')
            p = 1;
        if(s[0] == 'C')
            p = 2;
        if(s[0] == 'H')
            p = 3;
        if(s[0] == 'S')
            p = 4;
        q = s[1] - '0';
        if(s[1] == 'A')
            q = 1;
        if(s[1] == 'T')
            q = 10;
        if(s[1] == 'J')
            q = 11;
        if(s[1] == 'Q')
            q = 12;
        if(s[1] == 'K')
            q = 13;
        tong[p][q]++;
    }
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 13;j++)
            if(tong[i][j] == 0)
                ans++;
    cout << ans;
    return 0;
}
