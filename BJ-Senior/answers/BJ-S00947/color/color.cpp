#include<bits/stdc++.h>
using namespace std;

long long T;
long long n;
long long a[200010];
long long sum=0;

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            long long ge=0;
            while(a[i]==a[i+ge])
            {
                ge++;
            }
            if(ge>=2) sum=sum+(a[i]*(ge-1));
            i=i+ge-1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
