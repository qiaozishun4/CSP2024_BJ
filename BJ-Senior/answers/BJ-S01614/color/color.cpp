#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],c[1000005],sum;
bool b[1000005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>n;
    while(n--)
    {
        sum=0;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            b[i]=0;
            c[i]=0;
        }
        for(int i=0;i<m;i++) for(int j=i-1;j>=0;j--) if(a[j]==a[i]) c[i]=a[i];
        for(int i=0;i<m;i++) sum+=c[i];
        cout<<sum<<endl;
    }
    return 0;
}
