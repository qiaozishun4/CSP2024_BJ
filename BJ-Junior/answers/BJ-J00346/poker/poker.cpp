/*
15m
100
100
60
5
*/
#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
bool hv[64];
//CSHD
//1234
int Have_num(string s) {
    int number;
    if (s[1] == 'A') number = 1;
    else if (s[1] >= '2' && s[1] <= '9') number = s[1] - '0';
    else if (s[1] == 'T') number = 10;
    else if (s[1] == 'J') number = 11;
    else if (s[1] == 'Q') number = 12;
    else number = 13;
    int c;
    if (s[0] == 'C') c = 1;
    else if (s[0] == 'S') c = 2;
    else if (s[0] == 'H') c = 3;
    else c = 4;
    return number + (c - 1) * 13;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> s;
        hv[Have_num(s)] = true;
        //cout << Have_num(s) << endl;
    }
    for (int i = 1; i < 53; i++)
        if (!hv[i])
            ans++;
    cout << ans << endl;
    return 0;
}
/*
5
SA
SJ
HK
CJ
SA
48
*/
/*
5
SA
SA
SA
SA
SA
51
*/
/*
5
SA
S2
S3
S2
SA
49
*/
/*
10
SA
CA
HA
DA
S2
C2
H2
D2
SA
H3
*/
/*
52
DA
CA
HA
SA
D2
C2
H2
S2
D3
C3
H3
S3
D4
C4
H4
S4
D5
C5
H5
S5
D6
C6
H6
S6
D7
C7
H7
S7
D8
C8
H8
S8
D9
C9
H9
S9
DT
CT
HT
ST
DJ
CJ
HJ
SJ
DQ
CQ
HQ
SQ
DK
CK
HK
SA
1
*/
