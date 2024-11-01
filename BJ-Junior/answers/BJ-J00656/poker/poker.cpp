#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
ll n,ans=0;
char num[20]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char t[10]={'D','C','H','S'};
map<string,bool> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        m[a]=1;
    }
    for(ll i=0;i<13;i++)
    {
        for(ll j=0;j<4;j++)
        {
            string a;
            a+=t[j];a+=num[i];
            if(m[a]) ans++;
        }
    }
    cout<<52-ans;
    return 0;
}
