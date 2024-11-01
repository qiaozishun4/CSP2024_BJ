#include<bits/stdc++.h>
using namespace std;
bool book[6][20];
int n,cnt;
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int line,column;
        if(a=='D')line=0;
        if(a=='C')line=1;
        if(a=='H')line=2;
        if(a=='S')line=3;

        if(b=='A')column=1;
        if(b=='2')column=2;
        if(b=='3')column=3;
        if(b=='4')column=4;
        if(b=='5')column=5;
        if(b=='6')column=6;
        if(b=='7')column=7;
        if(b=='8')column=8;
        if(b=='9')column=9;
        if(b=='T')column=10;
        if(b=='J')column=11;
        if(b=='Q')column=12;
        if(b=='K')column=13;

        book[line][column]=1;
    }
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++)if(book[i][j]==0)cnt++;
    }
    cout<<cnt;
    return 0;
}
