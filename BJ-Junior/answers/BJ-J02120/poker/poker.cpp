#include <bits/stdc++.h>
using namespace std;
string a[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int t;
    cin>>t;
    int ans=52;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
        ans--;
        for(int j=1;j<i;j++)
        {
            if(a[i]==a[j])
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}