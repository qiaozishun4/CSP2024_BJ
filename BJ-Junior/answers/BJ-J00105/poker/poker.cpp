#include<iostream>
using namespace std;
char c1[55], c2[55];
int a[55][55];
int n;
int cnt = 0;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> c1[i] >> c2[i];
        if(c1[i] == 'D')
        {
            if(c2[i] == 'A') a[1][1]++;
            else if(c2[i] == 'T') a[1][10]++;
            else if(c2[i] == 'J') a[1][11]++;
            else if(c2[i] == 'Q') a[1][12]++;
            else if(c2[i] == 'K') a[1][13]++;
            else a[1][c2[i] - '0']++;
        }
        else if(c1[i] == 'C')
        {
            if(c2[i] == 'A') a[2][1]++;
            else if(c2[i] == 'T') a[2][10]++;
            else if(c2[i] == 'J') a[2][11]++;
            else if(c2[i] == 'Q') a[2][12]++;
            else if(c2[i] == 'K') a[2][13]++;
            else a[2][c2[i] - '0']++;
        }
        else if(c1[i] == 'H')
        {
            if(c2[i] == 'A') a[3][1]++;
            else if(c2[i] == 'T') a[3][10]++;
            else if(c2[i] == 'J') a[3][11]++;
            else if(c2[i] == 'Q') a[3][12]++;
            else if(c2[i] == 'K') a[3][13]++;
            else a[3][c2[i] - '0']++;
        }

        else
        {
            if(c2[i] == 'A') a[4][1]++;
            else if(c2[i] == 'T') a[4][10]++;
            else if(c2[i] == 'J') a[4][11]++;
            else if(c2[i] == 'Q') a[4][12]++;
            else if(c2[i] == 'K') a[4][13]++;
            else a[4][c2[i] - '0']++;
        }

    }
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            if(a[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
