#include <bits/stdc++.h>
using namespace std;
bool card[5][15];
int main (){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    memset(card,0,sizeof(card));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='A')card[1][1]=true;
            if(s[1]=='2')card[1][2]=true;
            if(s[1]=='3')card[1][3]=true;
            if(s[1]=='4')card[1][4]=true;
            if(s[1]=='5')card[1][5]=true;
            if(s[1]=='6')card[1][6]=true;
            if(s[1]=='7')card[1][7]=true;
            if(s[1]=='8')card[1][8]=true;
            if(s[1]=='9')card[1][9]=true;
            if(s[1]=='T')card[1][10]=true;
            if(s[1]=='J')card[1][11]=true;
            if(s[1]=='Q')card[1][12]=true;
            if(s[1]=='K')card[1][13]=true;
        }
        if(s[0]=='C'){
            if(s[1]=='A')card[2][1]=true;
            if(s[1]=='2')card[2][2]=true;
            if(s[1]=='3')card[2][3]=true;
            if(s[1]=='4')card[2][4]=true;
            if(s[1]=='5')card[2][5]=true;
            if(s[1]=='6')card[2][6]=true;
            if(s[1]=='7')card[2][7]=true;
            if(s[1]=='8')card[2][8]=true;
            if(s[1]=='9')card[2][9]=true;
            if(s[1]=='T')card[2][10]=true;
            if(s[1]=='J')card[2][11]=true;
            if(s[1]=='Q')card[2][12]=true;
            if(s[1]=='K')card[2][13]=true;
        }
        if(s[0]=='H'){
            if(s[1]=='A')card[3][1]=true;
            if(s[1]=='2')card[3][2]=true;
            if(s[1]=='3')card[3][3]=true;
            if(s[1]=='4')card[3][4]=true;
            if(s[1]=='5')card[3][5]=true;
            if(s[1]=='6')card[3][6]=true;
            if(s[1]=='7')card[3][7]=true;
            if(s[1]=='8')card[3][8]=true;
            if(s[1]=='9')card[3][9]=true;
            if(s[1]=='T')card[3][10]=true;
            if(s[1]=='J')card[3][11]=true;
            if(s[1]=='Q')card[3][12]=true;
            if(s[1]=='K')card[3][13]=true;
        }
        if(s[0]=='S'){
            if(s[1]=='A')card[4][1]=true;
            if(s[1]=='2')card[4][2]=true;
            if(s[1]=='3')card[4][3]=true;
            if(s[1]=='4')card[4][4]=true;
            if(s[1]=='5')card[4][5]=true;
            if(s[1]=='6')card[4][6]=true;
            if(s[1]=='7')card[4][7]=true;
            if(s[1]=='8')card[4][8]=true;
            if(s[1]=='9')card[4][9]=true;
            if(s[1]=='T')card[4][10]=true;
            if(s[1]=='J')card[4][11]=true;
            if(s[1]=='Q')card[4][12]=true;
            if(s[1]=='K')card[4][13]=true;
        }

    }
    int ans=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(card[i][j]==true)ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
