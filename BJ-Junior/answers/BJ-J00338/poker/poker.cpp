#include <iostream>
using namespace std;
#define ll long long
ll n;
string s[60];
ll ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    if(n==1)
    {
        cout<<"51";
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(s[i]==s[j])
            {
                s[j]="0";
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]!="0")
        {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
