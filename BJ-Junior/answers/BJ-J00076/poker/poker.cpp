#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,b[10][20],cnt;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int x,y;
        if(s[0]=='D')x=1;
        if(s[0]=='C')x=2;
        if(s[0]=='H')x=3;
        if(s[0]=='S')x=4;
        if(s[1]>='2'&&s[1]<='9')y=s[1]-'0';
        if(s[1]=='A')y=1;
        if(s[1]=='T')y=10;
        if(s[1]=='J')y=11;
        if(s[1]=='Q')y=12;
        if(s[1]=='K')y=13;
        b[x][y]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]!=1)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}