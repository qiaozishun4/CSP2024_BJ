#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
map<int,int> mp;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int maxx=0;
    for(int i=1;i<=n;i++) maxx=max(maxx,mp[a[i]]);
    cout<<maxx;
    return 0;
}
