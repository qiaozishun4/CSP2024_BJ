#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    map<string,bool> mp;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        mp[s]=1;
    }
    int cnt=0;
    for(map<string,bool>::iterator it=mp.begin();it!=mp.end();it++)
    {
        cnt++;
    }
    cout<<52-cnt;
    return 0;
}
