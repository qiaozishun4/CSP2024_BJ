#include<iostream>
#include<cstdio>
#include<cstring>
bool d[14];
bool c[14];
bool h[14];
bool s[14];
using namespace std;
int f(char c)
{
    if('2'<=c&&c<='9') return c-'0';
    else if(c=='T') return 10;
    else if(c=='J') return 11;
    else if(c=='Q') return 12;
    else if(c=='K') return 13;
    else return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    if(n==1) cout<<51<<'\n';
    else
    {
        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            if(str[0]=='D')
                d[f(str[1])]=true;
            else if(str[0]=='C')
                c[f(str[1])]=true;
            else if(str[0]=='H')
                h[f(str[1])]=true;
            else
                s[f(str[1])]=true;
        }
    }
    int cnt=0;
    for(int i=1; i<=13; i++)
    {
        if(!d[i]) cnt++;
        if(!c[i]) cnt++;
        if(!h[i]) cnt++;
        if(!s[i]) cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
