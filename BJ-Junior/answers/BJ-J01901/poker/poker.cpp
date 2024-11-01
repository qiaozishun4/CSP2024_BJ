#include<bits/stdc++.h>
using namespace std;
int n;
char ch[60][2];
int a[13][4],sum;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch[i][0]>>ch[i][1];
        if(ch[i][0]=='D'){
            if(ch[i][1]=='A') a[0][0]++;
            else if(ch[i][1]=='2') a[1][0]++;
            else if(ch[i][1]=='3') a[2][0]++;
            else if(ch[i][1]=='4') a[3][0]++;
            else if(ch[i][1]=='5') a[4][0]++;
            else if(ch[i][1]=='6') a[5][0]++;
            else if(ch[i][1]=='7') a[6][0]++;
            else if(ch[i][1]=='8') a[7][0]++;
            else if(ch[i][1]=='9') a[8][0]++;
            else if(ch[i][1]=='T') a[9][0]++;
            else if(ch[i][1]=='J') a[10][0]++;
            else if(ch[i][1]=='Q') a[11][0]++;
            else a[12][0]++;
        }
        else if(ch[i][0]=='C'){
            if(ch[i][1]=='A') a[0][1]++;
            else if(ch[i][1]=='2') a[1][1]++;
            else if(ch[i][1]=='3') a[2][1]++;
            else if(ch[i][1]=='4') a[3][1]++;
            else if(ch[i][1]=='5') a[4][1]++;
            else if(ch[i][1]=='6') a[5][1]++;
            else if(ch[i][1]=='7') a[6][1]++;
            else if(ch[i][1]=='8') a[7][1]++;
            else if(ch[i][1]=='9') a[8][1]++;
            else if(ch[i][1]=='T') a[9][1]++;
            else if(ch[i][1]=='J') a[10][1]++;
            else if(ch[i][1]=='Q') a[11][1]++;
            else a[12][1]++;
        }
        if(ch[i][0]=='H'){
            if(ch[i][1]=='A') a[0][2]++;
            else if(ch[i][1]=='2') a[1][2]++;
            else if(ch[i][1]=='3') a[2][2]++;
            else if(ch[i][1]=='4') a[3][2]++;
            else if(ch[i][1]=='5') a[4][2]++;
            else if(ch[i][1]=='6') a[5][2]++;
            else if(ch[i][1]=='7') a[6][2]++;
            else if(ch[i][1]=='8') a[7][2]++;
            else if(ch[i][1]=='9') a[8][2]++;
            else if(ch[i][1]=='T') a[9][2]++;
            else if(ch[i][1]=='J') a[10][2]++;
            else if(ch[i][1]=='Q') a[11][2]++;
            else a[12][2]++;
        }
        if(ch[i][0]=='S'){
            if(ch[i][1]=='A') a[0][3]++;
            else if(ch[i][1]=='2') a[1][3]++;
            else if(ch[i][1]=='3') a[2][3]++;
            else if(ch[i][1]=='4') a[3][3]++;
            else if(ch[i][1]=='5') a[4][3]++;
            else if(ch[i][1]=='6') a[5][3]++;
            else if(ch[i][1]=='7') a[6][3]++;
            else if(ch[i][1]=='8') a[7][3]++;
            else if(ch[i][1]=='9') a[8][3]++;
            else if(ch[i][1]=='T') a[9][3]++;
            else if(ch[i][1]=='J') a[10][3]++;
            else if(ch[i][1]=='Q') a[11][3]++;
            else a[12][3]++;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!a[j][i]) sum++;
        }
    }
    cout<<sum;
    return 0;
}
