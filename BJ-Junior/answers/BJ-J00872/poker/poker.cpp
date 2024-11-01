#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[52];
//long long s[51]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK","CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK","HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK","SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
//；气死力上面的不对
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    string p;
    for (int i = 1;i <= n;i++){
        cin >> p;
        //以下是破防代码
        if (p == "DA")  a[0]++;
        if (p == "D2")  a[1]++;
        if (p == "D3")  a[2]++;
        if (p == "D4")  a[3]++;
        if (p == "D5")  a[4]++;
        if (p == "D6")  a[5]++;
        if (p == "D7")  a[6]++;
        if (p == "D8")  a[7]++;
        if (p == "D9")  a[8]++;
        if (p == "DT")  a[9]++;
        if (p == "DJ")  a[10]++;
        if (p == "DQ")  a[11]++;
        if (p == "DK")  a[12]++;
        if (p == "CA")  a[13]++;
        if (p == "C2")  a[14]++;
        if (p == "C3")  a[15]++;
        if (p == "C4")  a[16]++;
        if (p == "C5")  a[17]++;
        if (p == "C6")  a[18]++;
        if (p == "C7")  a[19]++;
        if (p == "C8")  a[20]++;
        if (p == "C9")  a[21]++;
        if (p == "CT")  a[22]++;
        if (p == "CJ")  a[23]++;
        if (p == "CQ")  a[24]++;
        if (p == "CK")  a[25]++;
        if (p == "HA")  a[26]++;
        if (p == "H2")  a[27]++;
        if (p == "H3")  a[28]++;
        if (p == "H4")  a[29]++;
        if (p == "H5")  a[30]++;
        if (p == "H6")  a[31]++;
        if (p == "H7")  a[32]++;
        if (p == "H8")  a[33]++;
        if (p == "H9")  a[34]++;
        if (p == "HT")  a[35]++;
        if (p == "HJ")  a[36]++;
        if (p == "HQ")  a[37]++;
        if (p == "HK")  a[38]++;
        if (p == "SA")  a[39]++;
        if (p == "S2")  a[40]++;
        if (p == "S3")  a[41]++;
        if (p == "S4")  a[42]++;
        if (p == "S5")  a[43]++;
        if (p == "S6")  a[44]++;
        if (p == "S7")  a[45]++;
        if (p == "S8")  a[46]++;
        if (p == "S9")  a[47]++;
        if (p == "ST")  a[48]++;
        if (p == "SJ")  a[49]++;
        if (p == "SQ")  a[50]++;
        if (p == "SK")  a[51]++;
    }
    for (int i = 0;i < 52;i++){
        if (a[i]==0){
            sum++;
        }
    }
    cout << sum;
    return 0;
}