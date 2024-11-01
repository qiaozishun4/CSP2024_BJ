#include<bits/stdc++.h>
using namespace std;
long long a[200002];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if(a[i]==a[j])
                    ans+=a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}