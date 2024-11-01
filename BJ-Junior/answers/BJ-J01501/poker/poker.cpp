#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
bool poker[13][4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int t1,t2;
        if(s[0]=='D') t1=0;
        else if(s[0]=='C') t1=1;
        else if(s[0]=='H') t1=2;
        else t1=3;
        if(s[1]=='A') t2=1;
        else if(s[1]=='T') t2=10;
        else if(s[1]=='J') t2=11;
        else if(s[1]=='Q') t2=12;
        else if(s[1]=='K') t2=13;
        else t2=s[1]-'0';
        poker[t2-1][t1]=1;
    }
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(!poker[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}