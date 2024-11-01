#include<bits/stdc++.h>
using namespace std;
char a[5];
long long b[14][5],n,e;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='S') a[0]='1';
        if(a[0]=='C') a[0]='2';
        if(a[0]=='D') a[0]='3';
        if(a[0]=='H') a[0]='4';
        if(a[1]=='A') a[1]='1';
        if(a[1]=='T') a[1]='9'+1;
        if(a[1]=='J') a[1]='9'+2;
        if(a[1]=='Q') a[1]='9'+3;
        if(a[1]=='K') a[1]='9'+4;
        b[a[1]-'0'][a[0]-'0']=1;
    }
    for(int i=1;i<=13;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(b[i][j]==0)
            {
                e++;
            }
        }
    }
    cout<<e;
    return 0;
}