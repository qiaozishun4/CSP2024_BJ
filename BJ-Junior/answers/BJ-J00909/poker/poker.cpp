#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n;
string a[N];
set<string>s;
int ans=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i],s.insert(a[i]);
    ans=s.size();
    cout<<52-ans;
    return 0;
}