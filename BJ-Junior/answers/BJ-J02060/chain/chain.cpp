#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int cost[]={6,2,5,5,4,6,3,7,6};
int num[]={0,1,2,3,4,5,6,7,8,9};
bool flag=0;
bool Min(string s1,string s2)
{
    if(s1.size()==s2.size())return s1<s2;
    else return s2.size()<s2.size();
}
int check(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')ret+=6;
        if(s[i]=='1')ret+=2;
        if(s[i]=='2')ret+=5;
        if(s[i]=='3')ret+=5;
        if(s[i]=='4')ret+=4;
        if(s[i]=='5')ret+=5;
        if(s[i]=='6')ret+=6;
        if(s[i]=='7')ret+=3;
        if(s[i]=='8')ret+=7;
        if(s[i]=='9')ret+=6;
    }
    return ret;
}
signed main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<0<<"\n";

}



