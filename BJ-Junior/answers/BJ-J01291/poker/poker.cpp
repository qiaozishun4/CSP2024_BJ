#include<bits/stdc++.h>
using namespace std;
char at[]={'D','C','H','S'},bt[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
map<pair<char,char>,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        cin>>a>>b;
        mp[{a,b}]++;
    }
    int cnt=0;
    for(int i=0;i<4;i++)
    for(int j=0;j<13;j++)
    {
        char a=at[i],b=bt[j];
        if(!mp.count({a,b})) cnt++;
    }
    cout<<cnt;
    return 0;
}