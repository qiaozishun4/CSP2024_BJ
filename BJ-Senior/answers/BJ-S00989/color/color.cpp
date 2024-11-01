#include<iostream>
#include<cstdio>
using namespace std;
int n,c,a[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    for(int iii=0;iii<T;iii++)
    {
        c=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]==a[j]) c+=a[j];
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
