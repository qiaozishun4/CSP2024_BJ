#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
int n,poker[5][15]={},cnt=0;
char s[55][2];
cin>>n;
for(int i=1;i<=n;i++){
    int row=0,col=0;
    cin>>s[i];
    if(s[i][0]=='D')row=1;
    else if(s[i][0]=='C')row=2;
    else if(s[i][0]=='H')row=3;
    else if(s[i][0]=='S')row=4;
    if(s[i][1]=='A')col=1;
    else if(s[i][1]=='2')col=2;
    else if(s[i][1]=='3')col=3;
    else if(s[i][1]=='4')col=4;
    else if(s[i][1]=='5')col=5;
    else if(s[i][1]=='6')col=6;
    else if(s[i][1]=='7')col=7;
    else if(s[i][1]=='8')col=8;
    else if(s[i][1]=='9')col=9;
    else if(s[i][1]=='T')col=10;
    else if(s[i][1]=='J')col=11;
    else if(s[i][1]=='Q')col=12;
    else if(s[i][1]=='K')col=13;
    if(row!=0&&col!=0)poker[row][col]=1;
}
for(int i=1;i<=4;i++){
    for(int j=1;j<=13;j++){
        if(poker[i][j]==0)cnt++;
    }
}
cout<<cnt;
return 0;
}