#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[10][25];
int it[200];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    it['A'] = 1;
    it['2'] = 2;
    it['3'] = 3;
    it['4'] = 4;
    it['5'] = 5;
    it['6'] = 6;
    it['7'] = 7;
    it['8'] = 8;
    it['9'] = 9;
    it['T'] = 10;
    it['J'] = 11;
    it['Q'] = 12;
    it['K'] = 13;

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >>s;
        int x;
        if(s[0] == 'D')
        {

            x = 4;
        }
        else if(s[0] == 'C')
        {

            x = 3;
        }
        else if(s[0] == 'H')
        {

            x = 2;
        }
        else if(s[0] == 'S')
        {

            x = 1;
        }
        int y = it[s[1]];
        a[x][y]++;
    }
    int ans = 0;
    for(int i = 1; i <= 4; i++)
    {

        for(int j = 1; j <= 13; j++)
        {

            if(a[i][j] == 0) ans++;
        }
    }
    cout << ans <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
