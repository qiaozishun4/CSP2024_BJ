#include<bits/stdc++.h>
using namespace std;
int n,pok_num = 52,ans;
string cin1[101];
string pok1[13] = {"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK"};
string pok2[13] = {"CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK"};
string pok3[13] = {"HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK"};
string pok4[13] = {"SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
bool flagD[13],flagC[13],flagH[13],flagS[13];
int main(){
    for(int i = 0;i <= 12;i++){
        flagD[i] = true;
        flagC[i] = true;
        flagH[i] = true;
        flagS[i] = true;
    }
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> cin1[i];
    }
    for(int i = 1;i <= n;i++){
        ans = 0;
        for(int j = 0;j <= 12;j++){
            if(cin1[i] == pok1[j] && flagD[j] == true){
                 ++ans;
                 flagD[j] = false;
            }
        }
        for(int j = 0;j <= 12;j++){
            if(cin1[i] == pok2[j] && flagC[j] == true){
                ++ans;
                flagC[j] = false;
            }
        }
        for(int j = 0;j <= 12;j++){
            if(cin1[i] == pok3[j] && flagH[j] == true){
                ++ans;
                flagH[j] = false;
            }
        }
        for(int j = 0;j <= 12;j++){
 //           cout << j << " " << cin1[i] << " " << pok4[j] << " " << flagS[j] << endl;
            if(cin1[i] == pok4[j] && flagS[j] == true){
                ++ans;
                flagS[j] = false;
            }
        }
        pok_num -= ans;
//      cout << ans << " " << cin1[i] << endl;
    }
  //  if("SA" == "SA") cout << 11;
    cout << pok_num;
    return 0;
}
