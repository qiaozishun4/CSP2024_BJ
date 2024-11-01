#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
//char huase[]={'D','C','H','S'};
map<string,int>mp;
signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string tmp;
        cin>>tmp;
        mp[tmp]=1;
    }
    cout<<52-mp.size()<<"\n";
}


