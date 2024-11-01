#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    bool b[5][14] = {};
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; i ++)
    {
        cin >> s;
        if(s[0] == 'D')
        {
            if(s[1] == 'A')
                b[1][1] = 1;
            else if(s[1] == 'T')
                b[1][10] = 1;
            else if(s[1] == 'J')
                b[1][11] = 1;
            else if(s[1] == 'Q')
                b[1][12] = 1;
            else if(s[1] == 'K')
                b[1][13] = 1;
            else
                b[1][s[1] - 48] = 1;
        }
        else if(s[0] == 'C')
        {
            if(s[1] == 'A')
                b[2][1] = 1;
            else if(s[1] == 'T')
                b[2][10] = 1;
            else if(s[1] == 'J')
                b[2][11] = 1;
            else if(s[1] == 'Q')
                b[2][12] = 1;
            else if(s[1] == 'K')
                b[2][13] = 1;
            else
                b[2][s[1] - 48] = 1;
        }
        else if(s[0] == 'H')
        {
            if(s[1] == 'A')
                b[3][1] = 1;
            else if(s[1] == 'T')
                b[3][10] = 1;
            else if(s[1] == 'J')
                b[3][11] = 1;
            else if(s[1] == 'Q')
                b[3][12] = 1;
            else if(s[1] == 'K')
                b[3][13] = 1;
            else
                b[3][s[1] - 48] = 1;
        }
        else if(s[0] == 'S')
        {
            if(s[1] == 'A')
                b[4][1] = 1;
            else if(s[1] == 'T')
                b[4][10] = 1;
            else if(s[1] == 'J')
                b[4][11] = 1;
            else if(s[1] == 'Q')
                b[4][12] = 1;
            else if(s[1] == 'K')
                b[4][13] = 1;
            else
                b[4][s[1] - 48] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 13; j ++)
            if(! b[i][j])
                cnt ++;
    cout << cnt;
    return 0;
}