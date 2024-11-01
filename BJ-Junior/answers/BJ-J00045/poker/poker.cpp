#include <bits/stdc++.h>
using namespace std;
bool flag[5][14];
int n, cnt;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        char h = s[0];
        char d = s[1];
        switch (h)
        {
            case 'S': switch (d)
                      {
                          case 'A': flag[1][1] = 1; break;
                          case '2': flag[1][2] = 1; break;
                          case '3': flag[1][3] = 1; break;
                          case '4': flag[1][4] = 1; break;
                          case '5': flag[1][5] = 1; break;
                          case '6': flag[1][6] = 1; break;
                          case '7': flag[1][7] = 1; break;
                          case '8': flag[1][8] = 1; break;
                          case '9': flag[1][9] = 1; break;
                          case 'T': flag[1][10] = 1; break;
                          case 'J': flag[1][11] = 1; break;
                          case 'Q': flag[1][12] = 1; break;
                          case 'K': flag[1][13] = 1; break;
                      } break;
            case 'H': switch (d)
                      {
                          case 'A': flag[2][1] = 1; break;
                          case '2': flag[2][2] = 1; break;
                          case '3': flag[2][3] = 1; break;
                          case '4': flag[2][4] = 1; break;
                          case '5': flag[2][5] = 1; break;
                          case '6': flag[2][6] = 1; break;
                          case '7': flag[2][7] = 1; break;
                          case '8': flag[2][8] = 1; break;
                          case '9': flag[2][9] = 1; break;
                          case 'T': flag[2][10] = 1; break;
                          case 'J': flag[2][11] = 1; break;
                          case 'Q': flag[2][12] = 1; break;
                          case 'K': flag[2][13] = 1; break;
                      } break;
            case 'C': switch (d)
                      {
                          case 'A': flag[3][1] = 1; break;
                          case '2': flag[3][2] = 1; break;
                          case '3': flag[3][3] = 1; break;
                          case '4': flag[3][4] = 1; break;
                          case '5': flag[3][5] = 1; break;
                          case '6': flag[3][6] = 1; break;
                          case '7': flag[3][7] = 1; break;
                          case '8': flag[3][8] = 1; break;
                          case '9': flag[3][9] = 1; break;
                          case 'T': flag[3][10] = 1; break;
                          case 'J': flag[3][11] = 1; break;
                          case 'Q': flag[3][12] = 1; break;
                          case 'K': flag[3][13] = 1; break;
                      } break;
            case 'D': switch (d)
                      {
                          case 'A': flag[4][1] = 1; break;
                          case '2': flag[4][2] = 1; break;
                          case '3': flag[4][3] = 1; break;
                          case '4': flag[4][4] = 1; break;
                          case '5': flag[4][5] = 1; break;
                          case '6': flag[4][6] = 1; break;
                          case '7': flag[4][7] = 1; break;
                          case '8': flag[4][8] = 1; break;
                          case '9': flag[4][9] = 1; break;
                          case 'T': flag[4][10] = 1; break;
                          case 'J': flag[4][11] = 1; break;
                          case 'Q': flag[4][12] = 1; break;
                          case 'K': flag[4][13] = 1; break;
                      } break;
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 13; ++j)
        {
            if (flag[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
