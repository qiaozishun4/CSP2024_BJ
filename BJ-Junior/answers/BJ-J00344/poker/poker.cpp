#include<bits/stdc++.h>
using namespace std;
long long n, ans = 52;
bool y[14] = {0};
bool d[14] = {0};
bool r[14] = {0};
bool t[14] = {0};
string s[101];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        if(s[i] == "CA" && y[0] == false){
           y[0] = true;
           ans--;
        }
        else if(s[i] == "C2" && y[1] == false){
            y[1] = true;
           ans--;
        }
        else if(s[i] == "C3" && y[2] == false){
            y[2] = true;
           ans--;
        }
        else if(s[i] == "C4" && y[3] == false){
           y[3] = true;
           ans--;
        }
        else if(s[i] == "C5" && y[4] == false){
            y[4] = true;
           ans--;
        }
        else if(s[i] == "C6" && y[5] == false){
            y[5] = true;
           ans--;
        }
        else if(s[i] == "C7" && y[6] == false){
           y[6] = true;
           ans--;
        }
        else if(s[i] == "C8" && y[7] == false){
           y[7] = true;
           ans--;
        }
        else if(s[i] == "C9" && y[8] == false){
            y[8] = true;
           ans--;
        }
        else if(s[i] == "CT" && y[9] == false){
            y[9] = true;
           ans--;
        }
        else if(s[i] == "CJ" && y[10] == false){
            y[10] = true;
           ans--;
        }
        else if(s[i] == "CQ" && y[11] == false){
           y[11] = true;
           ans--;
        }
        else if(s[i] == "CK" && y[12] == false){
            y[12] = true;
           ans--;
        }
        else if(s[i] == "SA" && d[0] == false){
           y[0] = true;
           ans--;
        }
        else if(s[i] == "S2" && d[1] == false){
            d[1] = true;
           ans--;
        }
        else if(s[i] == "S3" && d[2] == false){
            d[2] = true;
           ans--;
        }
        else if(s[i] == "S4" && d[3] == false){
           d[3] = true;
           ans--;
        }
        else if(s[i] == "S5" && d[4] == false){
            d[4] = true;
           ans--;
        }
        else if(s[i] == "S6" && d[5] == false){
            d[5] = true;
           ans--;
        }
        else if(s[i] == "S7" && d[6] == false){
           d[6] = true;
           ans--;
        }
        else if(s[i] == "S8" && d[7] == false){
           d[7] = true;
           ans--;
        }
        else if(s[i] == "S9" && d[8] == false){
            d[8] = true;
           ans--;
        }
        else if(s[i] == "ST" && d[9] == false){
            d[9] = true;
           ans--;
        }
        else if(s[i] == "SJ" && d[10] == false){
            d[10] = true;
           ans--;
        }
        else if(s[i] == "SQ" && d[11] == false){
           d[11] = true;
           ans--;
        }
        else if(s[i] == "SK" && d[12] == false){
            d[12] = true;
           ans--;
        }
        else if(s[i] == "DA" && r[0] == false){
           r[0] = true;
           ans--;
        }
        else if(s[i] == "D2" && r[1] == false){
            r[1] = true;
           ans--;
        }
        else if(s[i] == "D3" && r[2] == false){
            r[2] = true;
           ans--;
        }
        else if(s[i] == "D4" && r[3] == false){
           r[3] = true;
           ans--;
        }
        else if(s[i] == "D5" && r[4] == false){
            r[4] = true;
           ans--;
        }
        else if(s[i] == "D6" && r[5] == false){
            r[5] = true;
           ans--;
        }
        else if(s[i] == "D7" && r[6] == false){
           r[6] = true;
           ans--;
        }
        else if(s[i] == "D8" && r[7] == false){
           r[7] = true;
           ans--;
        }
        else if(s[i] == "D9" && r[8] == false){
            r[8] = true;
           ans--;
        }
        else if(s[i] == "DT" && r[9] == false){
            r[9] = true;
           ans--;
        }
        else if(s[i] == "DJ" && r[10] == false){
            r[10] = true;
           ans--;
        }
        else if(s[i] == "DQ" && r[11] == false){
           r[11] = true;
           ans--;
        }
        else if(s[i] == "DK" && r[12] == false){
            r[12] = true;
           ans--;
        }
        if(s[i] == "HA" && y[0] == false){
           y[0] = true;
           ans--;
        }
        else if(s[i] == "H2" && t[1] == false){
            t[1] = true;
           ans--;
        }
        else if(s[i] == "H3" && t[2] == false){
            t[2] = true;
           ans--;
        }
        else if(s[i] == "H4" && t[3] == false){
           t[3] = true;
           ans--;
        }
        else if(s[i] == "H5" && t[4] == false){
            t[4] = true;
           ans--;
        }
        else if(s[i] == "H6" && t[5] == false){
            t[5] = true;
           ans--;
        }
        else if(s[i] == "H7" && t[6] == false){
           t[6] = true;
           ans--;
        }
        else if(s[i] == "H8" && t[7] == false){
           t[7] = true;
           ans--;
        }
        else if(s[i] == "H9" && t[8] == false){
            t[8] = true;
           ans--;
        }
        else if(s[i] == "HT" && t[9] == false){
            t[9] = true;
           ans--;
        }
        else if(s[i] == "HJ" && t[10] == false){
            t[10] = true;
           ans--;
        }
        else if(s[i] == "HQ" && t[11] == false){
           t[11] = true;
           ans--;
        }
        else if(s[i] == "HK" && t[12] == false){
            t[12] = true;
           ans--;
        }
    }
    if(n == 52){
        cout << "0";
        return 0;
    }
    cout << ans;

    return 0;
}
