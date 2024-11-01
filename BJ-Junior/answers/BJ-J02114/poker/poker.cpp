#include <bits/stdc++.h>
using namespace std;
int n;
char aa,bb,x[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'},y[10]={'D','C','H','S'};
long long ans;
map<pair<char,char>,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> aa >> bb;
        mp[make_pair(aa,bb)]++;
        //cout << aa << " " << bb << " " << mp[make_pair(aa,bb)] << "\n";
    }
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mp[make_pair(y[j],x[i])]==0) ans+=1;
            //cout << ans << " " << mp[make_pair(x[i],y[j])] << " " << x[i] << " " << y[j] << "\n";
        }
    }
    cout << ans;
    return 0;
}
