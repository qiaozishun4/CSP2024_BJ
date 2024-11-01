#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int ans = 52,c[52],n;
    cin >> n;
    string a[n],b[52];
    for (int i = 0;i < 52;i++)
    {
        c[i] = 0;
    }
    b[0] = "DA";
    b[1] = "D2";
    b[2] = "D3";
    b[3] = "D4";
    b[4] = "D5";
    b[5] = "D6";
    b[6] = "D7";
    b[7] = "D8";
    b[8] = "D9";
    b[9] = "DT";
    b[10] = "DJ";
    b[11] = "DQ";
    b[12] = "DK";
    b[13] = "CA";
    b[14] = "C2";
    b[15] = "C3";
    b[16] = "C4";
    b[17] = "C5";
    b[18] = "C6";
    b[19] = "C7";
    b[20] = "C8";
    b[21] = "C9";
    b[22] = "CT";
    b[23] = "CJ";
    b[24] = "CQ";
    b[25] = "CK";
    b[26] = "HA";
    b[27] = "H2";
    b[28] = "H3";
    b[29] = "H4";
    b[30] = "H5";
    b[31] = "H6";
    b[32] = "H7";
    b[33] = "H8";
    b[34] = "H9";
    b[35] = "HT";
    b[36] = "HJ";
    b[37] = "HQ";
    b[38] = "HK";
    b[39] = "SA";
    b[40] = "S2";
    b[41] = "S3";
    b[42] = "S4";
    b[43] = "S5";
    b[44] = "S6";
    b[45] = "S7";
    b[46] = "S8";
    b[47] = "S9";
    b[48] = "ST";
    b[49] = "SJ";
    b[50] = "SQ";
    b[51] = "SK";
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        for (int j = 0;j < 52;j++)
        {
            if (a[i] == b[j])
            {
                c[j] = 1;
                break;
            }
        }
    }
    for (int k = 0;k < 52;k++)
    {
        ans -= c[k];
    }
    cout << ans;
    return 0;
}