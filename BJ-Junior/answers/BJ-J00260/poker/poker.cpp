#include <iostream>
#include <cstdio>
using namespace std;
int f[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for(int i=1; i<=n; i++)
    {
        cin >> s;
        int d;
        if(s[0]=='D') d=0;
        if(s[0]=='C') d=1;
        if(s[0]=='H') d=2;
        if(s[0]=='S') d=3;
        int h;
        if(s[1]=='A') h=1;
        else if(s[1]=='T') h=10;
        else if(s[1]=='J') h=11;
        else if(s[1]=='Q') h=12;
        else if(s[1]=='K') h=13;
        else h=s[1]-'0';
        f[d*13+h]=1;
    }
    int cs=0;
    for(int i=1; i<=52; i++)
        if(!f[i]) cs++;
    cout <<cs;
    return 0;
}