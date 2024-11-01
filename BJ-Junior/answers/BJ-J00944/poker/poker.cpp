#include <bits/stdc++.h>
using namespace std;
int a[5][14],b,cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","r",stdout);
    cin>>b;
    for(int i=1;i<=b;i++){
        string s;
        cin>>s;
        if(s=="DA") a[1][1]=1;
        if(s=="D2") a[1][2]=1;
        if(s=="D3") a[1][3]=1;
        if(s=="D4") a[1][4]=1;
        if(s=="D5") a[1][5]=1;
        if(s=="D6") a[1][6]=1;
        if(s=="D7") a[1][7]=1;
        if(s=="D8") a[1][8]=1;
        if(s=="D9") a[1][9]=1;
        if(s=="DT") a[1][10]=1;
        if(s=="DJ") a[1][11]=1;
        if(s=="DQ") a[1][12]=1;
        if(s=="DK") a[1][13]=1;
        if(s=="CA") a[2][1]=1;
        if(s=="C2") a[2][2]=1;
        if(s=="C3") a[2][3]=1;
        if(s=="C4") a[2][4]=1;
        if(s=="C5") a[2][5]=1;
        if(s=="C6") a[2][6]=1;
        if(s=="C7") a[2][7]=1;
        if(s=="C8") a[2][8]=1;
        if(s=="C9") a[2][9]=1;
        if(s=="CT") a[2][10]=1;
        if(s=="CJ") a[2][11]=1;
        if(s=="CQ") a[2][12]=1;
        if(s=="CK") a[2][13]=1;
        if(s=="HA") a[3][1]=1;
        if(s=="H2") a[3][2]=1;
        if(s=="H3") a[3][3]=1;
        if(s=="H4") a[3][4]=1;
        if(s=="H5") a[3][5]=1;
        if(s=="H6") a[3][6]=1;
        if(s=="H7") a[3][7]=1;
        if(s=="H8") a[3][8]=1;
        if(s=="H9") a[3][9]=1;
        if(s=="HT") a[3][10]=1;
        if(s=="HJ") a[3][11]=1;
        if(s=="HQ") a[3][12]=1;
        if(s=="HK") a[3][13]=1;
        if(s=="SA") a[4][1]=1;
        if(s=="S2") a[4][2]=1;
        if(s=="S3") a[4][3]=1;
        if(s=="S4") a[4][4]=1;
        if(s=="S5") a[4][5]=1;
        if(s=="S6") a[4][6]=1;
        if(s=="S7") a[4][7]=1;
        if(s=="S8") a[4][8]=1;
        if(s=="S9") a[4][9]=1;
        if(s=="ST") a[4][10]=1;
        if(s=="SJ") a[4][11]=1;
        if(s=="SQ") a[4][12]=1;
        if(s=="SK") a[4][13]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

