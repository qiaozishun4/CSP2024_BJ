#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    string s;
    cin>>n;
    while(n--)cin>>s,m[s]++;
    for(auto i:m)cnt++;
    cout<<52-cnt;
}