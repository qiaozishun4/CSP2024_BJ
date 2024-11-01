#include<bits/stdc++.h>
using namespace std;
bool flag[4][13];
int a=0,b1=0,b2,cnt;
string b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        if(b[0]=='D')b1=0;
        else if(b[0]=='C')b1=1;
        else if(b[0]=='H')b1=2;
        else if(b[0]=='S')b1=3;
        else b1=b[0]-'0';
        if(b[1]=='A')b2=1;
        else if(b[1]=='T')b2=10;
        else if(b[1]=='J')b2=11;
        else if(b[1]=='Q')b2=12;
        else if(b[1]=='K')b2=13;
        else b2=b[1]-'0';
        flag[b1][b2-1]++;
    }
    for(int i=0;i<4;i++)for(int j=0;j<13;j++)if(flag[i][j])cnt++;
    cout<<52-cnt;
    return 0;
}