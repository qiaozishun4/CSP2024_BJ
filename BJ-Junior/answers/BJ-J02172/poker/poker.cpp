#include<bits/stdc++.h>
using namespace std;
bool a[6][15];
int n,x,y,cnt;
char s,r;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s>>r;
        if(s=='D')x=1;
        if(s=='C')x=2;
        if(s=='H')x=3;
        if(s=='S')x=4;
        if(r=='A')y=1;
        if(r=='2')y=2;
        if(r=='3')y=3;
        if(r=='4')y=4;
        if(r=='5')y=5;
        if(r=='6')y=6;
        if(r=='7')y=7;
        if(r=='8')y=8;
        if(r=='9')y=9;
        if(r=='T')y=10;
        if(r=='J')y=11;
        if(r=='Q')y=12;
        if(r=='K')y=13;
        a[x][y]=1;
   }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(a[i][j]==0)cnt++;
    cout<<cnt;
    return 0;
}
