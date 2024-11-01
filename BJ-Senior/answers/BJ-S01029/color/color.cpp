#include<bits/stdc++.h>
using namespace std;
const int N =1e6;
int a[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<=n;j++) cin>>a[j];
        cout<<n;
    }

    return 0;
}
