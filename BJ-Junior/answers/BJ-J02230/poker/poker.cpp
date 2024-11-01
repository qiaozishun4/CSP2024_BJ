#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s[53];
int main{
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++) cin >>s[i];
    sort(s+1,s+1+n);
    for(int i=2;i<=n;i++) if(s[i]!=s[i-1]) ans++;
    cout <<52-ans;
    return 0;
}