#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string a[n+1];
    int ans=52;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        bool f=1;
        for(int j=1;j<i;j++)
        {
            if (a[j]==a[i])
            {
                f=0;
                break;
            }
        }
        if (f)
        {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
