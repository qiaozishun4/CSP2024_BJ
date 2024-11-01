#include<bits/stdc++.h>
using namespace std;
int n,x,y,cnt;
bool flag[10][20];
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        char c1=s[0];
        char c2=s[1];
        if(c1=='D') x=1;
        else if(c1=='C') x=2;
        else if(c1=='H') x=3;
        else x=4;
        if(c2=='A') y=1;
        else if(c2=='T') y=10;
        else if(c2=='J') y=11;
        else if(c2=='Q') y=12;
        else if(c2=='K') y=13;
        else y=c2-'0';
        flag[x][y]=true;
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!flag[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
