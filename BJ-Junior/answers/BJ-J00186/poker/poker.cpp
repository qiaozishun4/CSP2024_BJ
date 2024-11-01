#include<bits/stdc++.h>
using namespace std;
int n,c[100],ans;
string s;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int t=0;
        if(s[0]=='D') t=13;
        if(s[0]=='C') t=2*13;
        if(s[0]=='H') t=3*13;
        if(s[1]<='9' && s[1]>='0') t+=s[1]-'0'-1;
        if(s[1]=='T') t+=9;
        if(s[1]=='J') t+=10;
        if(s[1]=='Q') t+=11;
        if(s[1]=='K') t+=12;
        c[t]++;
    }
    for(int i=0;i<=51;i++)
        if(c[i]==0) ans++;
    cout<<ans;
    return 0;
}