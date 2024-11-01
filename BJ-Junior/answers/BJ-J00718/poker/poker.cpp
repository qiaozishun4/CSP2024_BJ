#include <bits/stdc++.h>
using namespace std;
string ch[5][14];
string s[53];
int n,ans=52;
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ch[1][1]="DA";
    ch[1][2]="D2";
    ch[1][3]="D3";
    ch[1][4]="D4";
    ch[1][5]="D5";
    ch[1][6]="D6";
    ch[1][7]="D7";
    ch[1][8]="D8";
    ch[1][9]="D9";
    ch[1][10]="DT";
    ch[1][11]="DJ";
    ch[1][12]="DQ";
    ch[1][13]="DK";
    ch[2][1]="CA";
    ch[2][2]="C2";
    ch[2][3]="C3";
    ch[2][4]="C4";
    ch[2][5]="C5";
    ch[2][6]="C6";
    ch[2][7]="C7";
    ch[2][8]="C8";
    ch[2][9]="C9";
    ch[2][10]="CT";
    ch[2][11]="CJ";
    ch[2][12]="CQ";
    ch[2][13]="CK";
    ch[3][1]="HA";
    ch[3][2]="H2";
    ch[3][3]="H3";
    ch[3][4]="H4";
    ch[3][5]="H5";
    ch[3][6]="H6";
    ch[3][7]="H7";
    ch[3][8]="H8";
    ch[3][9]="H9";
    ch[3][10]="HT";
    ch[3][11]="HJ";
    ch[3][12]="HQ";
    ch[3][13]="HK";
    ch[4][1]="SA";
    ch[4][2]="S2";
    ch[4][3]="S3";
    ch[4][4]="S4";
    ch[4][5]="S5";
    ch[4][6]="S6";
    ch[4][7]="S7";
    ch[4][8]="S8";
    ch[4][9]="S9";
    ch[4][10]="ST";
    ch[4][11]="SJ";
    ch[4][12]="SQ";
    ch[4][13]="SK";
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(s[i]==s[j])
                ans++;
    for(int l=1;l<=n;l++)
        for(int i=1;i<=4;i++)
            for(int j=1;j<=13;j++)
                if(s[l]==ch[i][j])
                    ans--;
    cout<<ans;
    return 0;
}
