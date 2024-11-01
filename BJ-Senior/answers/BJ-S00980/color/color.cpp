#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000050];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out",'w',stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]==a[j])
                    ans+=a[i];
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
