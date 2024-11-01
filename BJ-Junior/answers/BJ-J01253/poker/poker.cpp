#include <bits/stdc++.h>

using namespace std;
map <char,int> mp;
bool d[14],c[14],h[14],s[14];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    mp['A']=1;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']=5;
    mp['6']=6;
    mp['7']=7;
    mp['8']=8;
    mp['9']=9;
    mp['T']=10;
    mp['J']=11;
    mp['Q']=12;
    mp['K']=13;

    int n;
    cin>>n;
    char hua,dian;
    for(int i=1;i<=n;i++)
    {
        cin>>hua>>dian;
        if(hua=='D') d[mp[dian]]=1;
        if(hua=='C') c[mp[dian]]=1;
        if(hua=='H') h[mp[dian]]=1;
        if(hua=='S') s[mp[dian]]=1;
    }
    int ans=0;
    for(int i=1;i<=13;i++)
    {
        if(d[i]==0) ans++;
        if(c[i]==0) ans++;
        if(h[i]==0) ans++;
        if(s[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
