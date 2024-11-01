#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string a[110];
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(mp[a[i]]==0) cnt++,mp[a[i]]++;
    }
    cout<<52-cnt;
    return 0;
}
