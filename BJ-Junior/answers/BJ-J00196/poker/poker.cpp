#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(m[s]==0)ans++,m[s]++;
    }
    cout<<52-ans;
    return 0;
}
