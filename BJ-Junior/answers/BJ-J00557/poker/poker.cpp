#include<bits/stdc++.h>
using namespace std;
char s[60][5];
bool flag[60];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i][0];
        cin >> s[i][1];
    }
    for(int i = 0; i < n; i++)
    {
        int num;
        if(s[i][0] == 'D')
        {
            num = 0;
        }
        if(s[i][0] == 'C')
        {
            num = 13;
        }
        if(s[i][0] == 'H')
        {
            num = 26;
        }
        if(s[i][0] == 'S')
        {
            num = 39;
        }
        if(s[i][1] == 'A') flag[num] = 1;
        if(s[i][1] >= '2' && s[i][1] <= '9') flag[int(s[i][1]) - '0' + num - 1] = 1;
        if(s[i][1] == 'T') flag[9 + num] = 1;
        if(s[i][1] == 'J') flag[10 + num] = 1;
        if(s[i][1] == 'Q') flag[11 + num] = 1;
        if(s[i][1] == 'K') flag[12 + num] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < 52; i++)
    {
        if(flag[i] == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
