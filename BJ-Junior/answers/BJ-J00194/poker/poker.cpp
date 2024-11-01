#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=52;
map<string,bool> mp;
signed main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    int i,j,k;
    string s;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>s;
        if (!mp[s])
            cnt--;
        mp[s]=1;
    }
    cout<<cnt<<endl;
}
