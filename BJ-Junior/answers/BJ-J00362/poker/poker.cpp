#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
long long n,ans;
string a;
map<string,bool>mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        if(mp[a]==false)
        {
            mp[a]=true;
            ++ans;
        }
    }
    printf("%lld\n",52-ans);
    return 0;
}