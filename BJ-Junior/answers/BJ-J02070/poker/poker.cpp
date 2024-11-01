#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out". "w", stdout);
    string p[55];
    int n;
    cin >> n;
    p[1] = "CA", p[2] = "C2", p[3] = "C3", p[4] = "C4", p[5] = "C5", p[6] = "C6", p[7] = "C7", p[8] = "C8", p[9] = "C9", p[10] = "CT", p[11] = "CJ", p[12] = "CQ", p[13] = "CK";
    p[14] = "DA", p[15] = "D2", p[16] = "D3", p[17] = "D4", p[18] = "D5", p[19] = "D6", p[20] = "D7", p[21] = "D8", p[22] = "D9", p[23] = "DT", p[24] = "DJ", p[25] = "DQ", p[26] = "DK";
    p[27] = "HA", p[28] = "H2", p[29] = "H3", p[30] = "H4", p[31] = "H5", p[32] = "H6", p[33] = "H7", p[34] = "H8", p[35] = "H9", p[36] = "HT", p[37] = "HJ", p[38] = "HQ", p[39] = "HK";
    p[40] = "SA", p[41] = "S2", p[42] = "S3", p[43] = "S4", p[44] = "S5", p[45] = "S6", p[46] = "S7", p[47] = "S8", p[48] = "S9", p[49] = "ST", p[50] = "SJ", p[51] = "SQ", p[52] = "SK";
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= 52; j++)
        {
            if (s == p[j])
            {
                p[j] = "0";
            }

        }
    }
    int sum = 0;
    for (int i = 1; i <= 52; i++)
    {
        if (p[i] != "0")
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
