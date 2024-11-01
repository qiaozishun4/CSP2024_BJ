#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,bool> mp;
    string pir[55]={""};
    char ia[]={"DCHS"},ib[]={"A23456789TJQK"};
    for(int i=0;i<52;i++)
    {
        pir[i]+=ia[i/13];
        pir[i]+=ib[i%13];
        mp[pir[i]]=1;
    }
    int n,ans=0;
    cin>>n;
    string x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        mp[x]=0;
    }
    for(int i=0;i<52;i++)
    {
        ans+=mp[pir[i]];
    }
    cout<<ans;
    return 0;
}