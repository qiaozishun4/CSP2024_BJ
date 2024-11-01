#include <bits/stdc++.h>
using namespace std;
int S1[53];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if (s == "DA"){
            S1[1]++;
        }
        if (s == "D2"){
            S1[2]++;
        }
        if (s == "D3"){
            S1[3]++;
        }
        if (s == "D4"){
            S1[4]++;
        }
        if (s == "D5"){
            S1[5]++;
        }
        if (s == "D6"){
            S1[6]++;
        }
        if (s == "D7"){
            S1[7]++;
        }
        if (s == "D8"){
            S1[8]++;
        }
        if (s == "D9"){
            S1[9]++;
        }
        if (s == "DT"){
            S1[10]++;
        }
        if (s == "DJ"){
            S1[11]++;
        }
        if (s == "DQ"){
            S1[12]++;
        }
        if (s == "DK"){
            S1[13]++;
        }
        if (s == "HA"){
            S1[14]++;
        }
        if (s == "H2"){
            S1[15]++;
        }
        if (s == "H3"){
            S1[16]++;
        }
        if (s == "H4"){
            S1[17]++;
        }
        if (s == "H5"){
            S1[18]++;
        }
        if (s == "H6"){
            S1[19]++;
        }
        if (s == "H7"){
            S1[20]++;
        }
        if (s == "H8"){
            S1[21]++;
        }
        if (s == "H9"){
            S1[22]++;
        }
        if (s == "HT"){
            S1[23]++;
        }
        if (s == "HJ"){
            S1[24]++;
        }
        if (s == "HQ"){
            S1[25]++;
        }
        if (s == "HK"){
            S1[26]++;
        }
        if (s == "CA"){
            S1[27]++;
        }
        if (s == "C2"){
            S1[28]++;
        }
        if (s == "C3"){
            S1[29]++;
        }
        if (s == "C4"){
            S1[30]++;
        }
        if (s == "C5"){
            S1[31]++;
        }
        if (s == "C6"){
            S1[32]++;
        }
        if (s == "C7"){
            S1[33]++;
        }
        if (s == "C8"){
            S1[34]++;
        }
        if (s == "C9"){
            S1[35]++;
        }
        if (s == "CT"){
            S1[36]++;
        }
        if (s == "CJ"){
            S1[37]++;
        }
        if (s == "CQ"){
            S1[38]++;
        }
        if (s == "CK"){
            S1[39]++;
        }
        if (s == "SA"){
            S1[40]++;
        }
        if (s == "S2"){
            S1[41]++;
        }
        if (s == "S3"){
            S1[42]++;
        }
        if (s == "S4"){
            S1[43]++;
        }
        if (s == "S5"){
            S1[44]++;
        }
        if (s == "S6"){
            S1[45]++;
        }
        if (s == "S7"){
            S1[46]++;
        }
        if (s == "S8"){
            S1[47]++;
        }
        if (s == "S9"){
            S1[48]++;
        }
        if (s == "ST"){
            S1[49]++;
        }
        if (s == "SJ"){
            S1[50]++;
        }
        if (s == "SQ"){
            S1[51]++;
        }
        if (s == "SK"){
            S1[52]++;
        }
    }int cnt = 0;
    for (int i = 1; i <= 52; i++){
        if (S1[i] == 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}