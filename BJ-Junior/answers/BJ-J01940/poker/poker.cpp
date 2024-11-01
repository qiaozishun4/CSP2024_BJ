#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
string s;
map<string,int>mp;
map<string,int>::iterator it;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        mp[s]=3;
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        ans++;
    }
    cout<<52-ans;
    return 0;
}
