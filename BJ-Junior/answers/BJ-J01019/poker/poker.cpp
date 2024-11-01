#include<bits/stdc++.h>
using namespace std;
int n;
int d[150],c[150],h[150],s[150];
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        if(mp[a]==1)
        {
            ans--;
        }
        else
        {
            mp[a]++;
        }
    }
    cout<<52-ans;
    return 0;
}
