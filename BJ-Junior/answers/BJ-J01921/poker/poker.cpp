#include<bits/stdc++.h>
using namespace std;
int f[5][15];
int n;
string s;
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        mp[s]=1;
    }
    cout<<52-mp.size();
    return 0;
}
