#include<bits/stdc++.h>
using namespace std;
bool d[14],c[14],h[14],s[14];
int a(char c)
{
    if(c=='A')return 1;
    if(c>='2'&&c<='9')return int(c-'0');
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        string s1;
        cin>>s1;
        if(s1[0]=='D')d[a(char(s1[1]))]=1;
        if(s1[0]=='C')c[a(char(s1[1]))]=1;
        if(s1[0]=='H')h[a(char(s1[1]))]=1;
        if(s1[0]=='S')s[a(char(s1[1]))]=1;
    }
    int cnt=0;
    for(int i=1;i<=13;i++)
    {
        if(!d[i])cnt++;
        if(!c[i])cnt++;
        if(!h[i])cnt++;
        if(!s[i])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
