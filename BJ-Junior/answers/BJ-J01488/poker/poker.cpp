#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    char a[53],b[53];
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>a[i]>>b[i];
    int ans = 52-n;
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i]==a[j]&&b[i]==b[j])
                ans++;
        }
    }
    if(ans>=0)
        cout<<ans;
    else
        cout<<0;
    return 0;
}
