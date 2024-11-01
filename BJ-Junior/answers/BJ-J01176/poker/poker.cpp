#include<iostream>
using namespace std;
long long a[10][50];
long long n,x,y;
long long ans;
string str;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(str[0]=='D') x=1;
        if(str[0]=='C') x=2;
        if(str[0]=='H') x=3;
        if(str[0]=='S') x=4;
        if(str[1]!='A'&&str[1]!='T'&&str[1]!='J'&&str[1]!='Q'&&str[1]!='K') y=str[1]-'0';
        else
        {
            if(str[1]=='A') y=1;
            if(str[1]=='T') y=10;
            if(str[1]=='J') y=11;
            if(str[1]=='Q') y=12;
            if(str[1]=='K') y=13;
        }
        a[x][y]=1;
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(a[i][j]==0) ans++;
    cout<<ans<<endl;
}
