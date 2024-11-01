#include<bits/stdc++.h>
using namespace std;
int n,d[50],c[50],h[50],s[50];
map <char,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
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
    for(int i=1;i<=n;i++)
    {
        char x,y;
        cin>>x>>y;
        if(x=='D'){
            d[mp[y]]=1;
        }else if(x=='C'){
            c[mp[y]]=1;
        }else if(x=='H'){
            h[mp[y]]=1;
        }else if(x=='S'){
            s[mp[y]]=1;
        }
    }
    int ans=52;
    for(int i=1;i<=13;i++)
    {
        ans=ans-d[i]-c[i]-h[i]-s[i];
    }
    cout<<ans;
    return 0;
}
