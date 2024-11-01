#include<bits/stdc++.h>
using namespace std;
int n=0;
bool poker[4][13]={0};
int ans=0;

int t(string s)
{
    if(s[0]=='D') return 0;
    if(s[0]=='C') return 1;
    if(s[0]=='H') return 2;
    if(s[0]=='S') return 3;
    return 0;
}

int num(string s)
{
    if(s[1]=='A') return 0;
    if(s[1]=='2') return 1;
    if(s[1]=='3') return 2;
    if(s[1]=='4') return 3;
    if(s[1]=='5') return 4;
    if(s[1]=='6') return 5;
    if(s[1]=='7') return 6;
    if(s[1]=='8') return 7;
    if(s[1]=='9') return 8;
    if(s[1]=='T') return 9;
    if(s[1]=='J') return 10;
    if(s[1]=='Q') return 11;
    if(s[1]=='K') return 12;
    return 0;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        poker[t(s)][num(s)]=1;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            if(poker[i][j]==0) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}