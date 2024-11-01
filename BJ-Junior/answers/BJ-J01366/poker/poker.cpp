#include<bits/stdc++.h>
using namespace std;
string a[60];
int ans=52;
int n;
int k;
int main()
{
    cin >> n;
    ans-=n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]==a[i])
            {
                ans++;
            }
            if(a[i]!=a[j])
            {
                i=j-1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
