#include<bits/stdc++.h>
using namespace std;
const int N=2E6+1;
int a[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int cnt=0;
        for(int i=2;i<=n;i++)
            if(a[i-1]==a[i])
                cnt+=a[i];
        cout<<cnt<<endl;
    }
    return 0;
}