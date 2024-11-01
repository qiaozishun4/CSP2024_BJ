#include <bits/stdc++.h>
using namespace std;
int n;
string a[55];
int b[5][14], num;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == "HT")
        {
            b[1][10]++;
        }
        else if (a[i] == "HJ")
        {
            b[1][11]++;

        }
        else if (a[i] == "HQ")
        {
            b[1][12]++;
        }
        else if (a[i] == "HK")
        {
            b[1][13]++;
        }
        else if (a[i] == "HA")
        {
            b[1][1]++;
        }
        else if (a[i] == "H2")
        {
            b[1][2]++;
        }
        else if (a[i] == "H3")
        {
            b[1][3]++;
        }
        else if (a[i] == "H4")
        {
            b[1][4]++;
        }
        else if (a[i] == "H5")
        {
            b[1][5]++;
        }
        else if (a[i] == "H6")
        {
            b[1][6]++;
        }
        else if (a[i] == "H7")
        {
            b[1][7]++;
        }
        else if (a[i] == "H8")
        {
            b[1][8]++;
        }
        else if (a[i] == "H9")
        {
            b[1][9]++;
        }
        else if (a[i] == "DT")
        {
            b[2][10]++;
        }
        else if (a[i] == "DJ")
        {
            b[2][11]++;
        }
        else if (a[i] == "DQ")
        {
            b[2][12]++;
        }
        else if (a[i] == "DK")
        {
            b[2][13]++;
        }
        else if (a[i] == "DA")
        {
            b[2][1]++;
        }
        else if (a[i] == "D2")
        {
            b[2][2]++;
        }
        else if (a[i] == "D3")
        {
            b[2][3]++;
        }
        else if (a[i] == "D4")
        {
            b[2][4]++;
        }
        else if (a[i] == "D5")
        {
            b[2][5]++;
        }
        else if (a[i] == "D6")
        {
            b[2][6]++;
        }
        else if (a[i] == "D7")
        {
            b[2][7]++;
        }
        else if (a[i] == "D8")
        {
            b[2][8]++;
        }
        else if (a[i] == "D9")
        {
            b[1][9]++;
        }
        else if (a[i] == "ST")
        {
            b[3][10]++;
        }
        else if (a[i] == "SJ")
        {
            b[3][11]++;
        }
        else if (a[i] == "SQ")
        {
            b[3][12]++;
        }
        else if (a[i] == "SK")
        {
            b[3][13]++;
        }
        else if (a[i] == "SA")
        {
            b[3][1]++;
        }
        else if (a[i] == "S2")
        {
            b[3][2]++;
        }
        else if (a[i] == "S3")
        {
            b[3][3]++;
        }
        else if (a[i] == "S4")
        {
            b[3][4]++;
        }
        else if (a[i] == "S5")
        {
            b[3][5]++;
        }
        else if (a[i] == "S6")
        {
            b[3][6]++;
        }
        else if (a[i] == "S7")
        {
            b[3][7]++;
        }
        else if (a[i] == "S8")
        {
            b[3][8]++;
        }
        else if (a[i] == "S9")
        {
            b[3][9]++;
        }
        else if (a[i] == "CT")
        {
            b[4][10]++;
        }
        else if (a[i] == "CJ")
        {
            b[4][11]++;
        }
        else if (a[i] == "CQ")
        {
            b[4][12]++;
        }
        else if (a[i] == "CK")
        {
            b[4][13]++;
        }
        else if (a[i] == "CA")
        {
            b[4][1]++;
        }
        else if (a[i] == "C2")
        {
            b[4][2]++;
        }
        else if (a[i] == "C3")
        {
            b[4][3]++;
        }
        else if (a[i] == "C4")
        {
            b[4][4]++;
        }
        else if (a[i] == "C5")
        {
            b[4][5]++;
        }
        else if (a[i] == "C6")
        {
            b[4][6]++;
        }
        else if (a[i] == "C7")
        {
            b[4][7]++;
        }
        else if (a[i] == "C8")
        {
            b[4][8]++;
        }
        else if (a[i] == "C9")
        {
            b[4][9]++;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (b[i][j] == 0)
            {
                num++;
            }
        }
    }
    cout << num;
    return 0;
}
