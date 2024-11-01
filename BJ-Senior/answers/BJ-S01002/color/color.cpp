#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200005];
int b[1000005];
int num[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int l=1;l<=t;++l)
    {
        cin>>n;
        int max=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i]>max)
                max=a[i];
            b[a[i]]++;
        }
        int maxx=0;
        for(int i=1;i<=max;++i)
        {
            if(b[i]*i-i>maxx)
            {
                maxx=b[i]*i-i;
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
