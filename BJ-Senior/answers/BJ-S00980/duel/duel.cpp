#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[100050];
int b[100050];
int c[100050];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out",'w',stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(a[i]<a[j]&&!c[i])
            {
                b[i]=1;
                c[i]=1;
            }

    }
    for(int i=1;i<=n;i++)
        ans+=b[i];
    ans=n-ans;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
