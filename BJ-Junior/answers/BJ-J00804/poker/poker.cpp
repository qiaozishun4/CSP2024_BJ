#include <bits/stdc++.h>
using namespace std;
char a[55],b[55];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans;
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=1;j<i;j++)
        {
            if(a[j]==a[i]&&b[j]==b[i])
            {
                ans--;
                break;
            }
        }
    }
    cout<<52-ans;
    return 0;
}