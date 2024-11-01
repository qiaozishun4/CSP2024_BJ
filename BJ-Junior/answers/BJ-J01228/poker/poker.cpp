#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string s;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        mp[s]++;
    }
    cout<<52-mp.size();
    return 0;
}