#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
map<string,bool> p;
int n,ans=0;
cin>>n;
for(int i=0;i<n;i++)
{
    string a;
    cin>>a;
    if(p[a]==0)
    {
        p[a]++;
        ans++;
    }
}
ans=52-ans;
cout<<ans;
return 0;
}

