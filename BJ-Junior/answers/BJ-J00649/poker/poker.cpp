#include<bits/stdc++.h>
using namespace std;
int a,b,t[15][15],n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        //reset
        string s;
        cin >> s;
        int num;
        if(s[1] == 'A') num = 1;
        else if(s[1] == 'T') num = 10;
        else if(s[1] == 'J') num = 11;
        else if(s[1] == 'Q') num = 12;
        else if(s[1] == 'K') num = 13;
        else num = (s[1] - '0');
        if(s[0] == 'D') t[0][num] ++;
        if(s[0] == 'C') t[1][num] ++;
        if(s[0] == 'H') t[2][num] ++;
        if(s[0] == 'S') t[3][num] ++;
    }
    int ans = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(t[i][j] == 0)    ans ++;
        }
    }
    cout << ans;
    return 0;
}
